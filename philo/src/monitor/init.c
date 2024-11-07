/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:54:30 by erijania          #+#    #+#             */
/*   Updated: 2024/11/07 15:18:37 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pl_types.h"
#include "pl_utils.h"
#include "pl_philo.h"

static void	init_vars(t_monitor *monitor)
{
	int		i;
	t_philo	*philo;
	t_sync	*fork;

	if (!monitor)
		return ;
	i = 0;
	while (i < monitor->size)
	{
		fork = &monitor->fork_list[i];
		philo = &monitor->philosopher_list[i];
		pthread_mutex_init(fork, 0);
		philosopher_init(philo, i++, fork);
		philo->monitor = monitor;
	}
	i = 0;
	while (i < monitor->size)
	{
		philo = &monitor->philosopher_list[i];
		fork = &monitor->fork_list[(i + 1) % monitor->size];
		if (philo->left_fork != fork)
			philo->right_fork = fork;
		i++;
	}
}

void	monitor_init(t_monitor *monitor, int length)
{
	pthread_mutex_init(&monitor->dead_lock, 0);
	pthread_mutex_init(&monitor->print_lock, 0);
	monitor->philosopher_list = (t_philo *)malloc(sizeof(t_philo) * length);
	monitor->fork_list = (t_sync *)malloc(sizeof(t_sync) * length);
	if (!monitor->philosopher_list || !monitor->fork_list)
		return ;
	monitor->size = length;
	monitor->start_time = get_timestamp();
	monitor->eat_limit = 0;
	monitor->time_to.die = 0;
	monitor->time_to.eat = 0;
	monitor->time_to.sleep = 0;
	monitor->dead = 0;
	init_vars(monitor);
}
