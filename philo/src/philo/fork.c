/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:43:44 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 12:09:22 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_monitor.h"
#include "pl_philo.h"
#include "pl_utils.h"
#include <unistd.h>

static void	put_back(t_sync *fork)
{
	
	if (!fork)
		return ;
	pthread_mutex_unlock(fork);
}

static void	take(t_philo *philo, t_sync *fork)
{
	if (!philo || !fork)
		return ;
	if (pthread_mutex_lock(fork) == 0)
	{
		if (pl_get_dead(philo->monitor))
		{
			put_back(fork);
			return ;
		}
		pl_msg(philo, "has taken a fork");
		philo->taken_fork++;
	}
}

int	pl_take_fork(t_philo *pl)
{
	if (pl->monitor->max_eat && pl->max_eat >= pl->monitor->max_eat)
	{
		pl_set_state(pl, PHILO_FULL);
		return (0);
	}
	if (pl->rank % 2 == 0)
	{
		take(pl, pl->left);
		take(pl, pl->right);
	}
	else
	{
		take(pl, pl->right);
		take(pl, pl->left);
	}
	return (pl->taken_fork == 2);
}

void	pl_free_fork(t_philo *pl)
{
	if (pl->rank % 2 == 0)
	{
		put_back(pl->right);
		put_back(pl->left);
	}
	else
	{
		put_back(pl->left);
		put_back(pl->right);
	}
	pl->taken_fork = 0;
}
