/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 19:36:18 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_fork.h"
#include "pl_utils.h"

static void	take_left_first(t_philo *pl)
{
	pthread_mutex_lock(&pl->left->use_lock);
	if (!pl->left->user)
	{
		pl->left->user = pl;
		pl_utl_message(pl, "has taken a fork");
	}
	pthread_mutex_unlock(&pl->left->use_lock);
	pthread_mutex_lock(&pl->right->use_lock);
	if (!pl->right->user)
	{
		pl->right->user = pl;
		pl_utl_message(pl, "has taken a fork");
	}
	pthread_mutex_unlock(&pl->right->use_lock);
}

static void	take_right_first(t_philo *pl)
{
	pthread_mutex_lock(&pl->right->use_lock);
	if (!pl->right->user)
	{
		pl->right->user = pl;
		pl_utl_message(pl, "has taken a fork");
	}
	pthread_mutex_unlock(&pl->right->use_lock);
	pthread_mutex_lock(&pl->left->use_lock);
	if (!pl->left->user)
	{
		pl->left->user = pl;
		pl_utl_message(pl, "has taken a fork");
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

void	pl_take_fork(t_philo *pl)
{
	if (pl->rank % 2 == 0)
		take_right_first(pl);
	else
		take_left_first(pl);
	if (can_use_fork(pl) && !is_max_eat_exceeded(pl))
	{
		pl->state = PHILO_EATING;
		pthread_mutex_lock(&pl->time_lock);
		pl->tt.die = pl->tab->tt.die + pl_utl_timestamp();
		pthread_mutex_unlock(&pl->time_lock);
		pl->max_eat++;
	}
}
