/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:43:44 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 14:54:28 by erijania         ###   ########.fr       */
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
	if (pl->monitor->eat_limit && pl->eat_times >= pl->monitor->eat_limit)
	{
		pl_set_state(pl, PHILO_FULL);
		return (0);
	}
	if (pl->rank % 2 == 0)
	{
		take(pl, pl->left_fork);
		take(pl, pl->right_fork);
	}
	else
	{
		take(pl, pl->right_fork);
		take(pl, pl->left_fork);
	}
	return (pl->taken_fork == 2);
}

void	pl_free_fork(t_philo *pl)
{
	if (pl->rank % 2 == 0)
	{
		put_back(pl->right_fork);
		put_back(pl->left_fork);
	}
	else
	{
		put_back(pl->left_fork);
		put_back(pl->right_fork);
	}
	pl->taken_fork = 0;
}
