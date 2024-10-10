/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/10/10 07:38:09 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_fork.h"
#include "pl_utils.h"

static void	take_left_first(t_philo *pl, long time)
{
	pthread_mutex_lock(&pl->left->use_lock);
	if (!pl->left->user)
	{
		pl->left->user = pl;
		pl_utl_message(pl, "has taken a fork", time);
	}
	pthread_mutex_unlock(&pl->left->use_lock);
	pthread_mutex_lock(&pl->right->use_lock);
	if (!pl->right->user)
	{
		pl->right->user = pl;
		pl_utl_message(pl, "has taken a fork", time);
	}
	pthread_mutex_unlock(&pl->right->use_lock);
}

static void	take_right_first(t_philo *pl, long time)
{
	pthread_mutex_lock(&pl->right->use_lock);
	if (!pl->right->user)
	{
		pl->right->user = pl;
		pl_utl_message(pl, "has taken a fork", time);
	}
	pthread_mutex_unlock(&pl->right->use_lock);
	pthread_mutex_lock(&pl->left->use_lock);
	if (!pl->left->user)
	{
		pl->left->user = pl;
		pl_utl_message(pl, "has taken a fork", time);
	}
	pthread_mutex_unlock(&pl->left->use_lock);
}

static int	can_use_fork(t_philo *pl)
{
	int	can_use;

	can_use = pl->left != pl->right;
	pthread_mutex_lock(&pl->left->use_lock);
	can_use = can_use && pl->left->user == pl;
	pthread_mutex_unlock(&pl->left->use_lock);
	pthread_mutex_lock(&pl->right->use_lock);
	can_use = can_use && pl->right->user == pl;
	pthread_mutex_unlock(&pl->right->use_lock);
	return (can_use);
}

void	pl_take_fork(t_philo *pl, long time)
{
	if (pl->rank % 2 == 0)
		take_right_first(pl, time);
	else
		take_left_first(pl, time);
	if (can_use_fork(pl) && !pl_is_full(pl))
	{
		pl->tt.die = pl->tab->tt.die + time;
		pl->max_eat++;
		pthread_mutex_lock(&pl->state_lock);
		pl->state = PHILO_EATING;
		if (pl->tab->max_eat && pl->max_eat > pl->tab->max_eat)
			pl->state = PHILO_FULL;
		pthread_mutex_unlock(&pl->state_lock);
	}
}
