/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 17:52:49 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_fork.h"
#include "pl_utils.h"

static void	take_left_first(t_philo *pl)
{
	pthread_mutex_lock(&pl->left->lock);
	if (!pl->left->user)
	{
		pl->left->user = pl;
		pl_utl_message(pl, "has taken a fork");
	}
	pthread_mutex_unlock(&pl->left->lock);
	pthread_mutex_lock(&pl->right->lock);
	if (!pl->right->user)
	{
		pl->right->user = pl;
		pl_utl_message(pl, "has taken a fork");
	}
	pthread_mutex_unlock(&pl->right->lock);
}

static void	take_right_first(t_philo *pl)
{
	pthread_mutex_lock(&pl->right->lock);
	if (!pl->right->user)
	{
		pl->right->user = pl;
		pl_utl_message(pl, "has taken a fork");
	}
	pthread_mutex_unlock(&pl->right->lock);
	pthread_mutex_lock(&pl->left->lock);
	if (!pl->left->user)
	{
		pl->left->user = pl;
		pl_utl_message(pl, "has taken a fork");
	}
	pthread_mutex_unlock(&pl->left->lock);
}

static int	can_use_fork(t_philo *pl)
{
	return (pl->left != pl->right
		&& pl->left->user == pl && pl->right->user == pl);
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
		pl->tt.die = pl->tab->tt.die + pl_utl_timestamp();
		pl->max_eat++;
	}
}
