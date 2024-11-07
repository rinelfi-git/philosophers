/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:43:44 by erijania          #+#    #+#             */
/*   Updated: 2024/11/07 15:22:04 by erijania         ###   ########.fr       */
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
		if (monitor_get_dead(philo->monitor))
		{
			put_back(fork);
			return ;
		}
		print_state(philo, "has taken a fork");
		philo->taken_fork++;
	}
}

int	do_take_fork(t_philo *philo)
{
	int		eat_limit;

	eat_limit = philo->monitor->eat_limit;
	if (eat_limit && philo->eat_times >= eat_limit)
	{
		set_philo_state(philo, PHILO_FULL);
		return (0);
	}
	if (philo->rank % 2)
	{
		take(philo, philo->left_fork);
		take(philo, philo->right_fork);
		if (philo->taken_fork == 1)
			put_back(philo->left_fork);
	}
	else
	{
		take(philo, philo->right_fork);
		take(philo, philo->left_fork);
		if (philo->taken_fork == 1)
			put_back(philo->right_fork);
	}
	return (philo->taken_fork == 2);
}

void	do_free_fork(t_philo *philo)
{
	if (philo->rank % 2)
	{
		put_back(philo->left_fork);
		put_back(philo->right_fork);
	}
	else
	{
		put_back(philo->right_fork);
		put_back(philo->left_fork);
	}
	philo->taken_fork = 0;
}
