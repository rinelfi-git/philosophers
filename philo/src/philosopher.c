/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 15:10:22 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_monitor.h"
#include "pl_philo.h"
#include "pl_types.h"
#include "pl_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	pl_join(void *self)
{
	t_philo	*philo;

	philo = (t_philo *)self;
	pthread_join(philo->thread, 0);
}

static void	pl_start(void *self)
{
	t_philo	*philo;

	philo = (t_philo *)self;
	philo->is_running = 1;
	if (pthread_create(&philo->thread, 0, philosopher_routine, philo) != 0)
		return ;
}

static int	simulation_running(t_monitor *monitor)
{
	int		i;
	t_state	state;
	t_philo	*philo;
	long	times[2];

	i = 0;
	monitor->ate_number = 0;
	times[0] = get_timestamp();
	while (i < monitor->size)
	{
		philo = &monitor->philosopher_list[i++];
		state = get_philo_state(philo);
		times[1] = get_last_meal(philo);
		if (state == PHILO_FULL)
			monitor->ate_number++;
		else if (times[1] > 0 && times[1] + monitor->time_to.die <= times[0])
		{
			philosopher_set_run(philo, 0);
			monitor_set_dead(monitor, philo);
			return (0);
		}
	}
	return (monitor->ate_number < monitor->size);
}

static void	*monitoring(void *self)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)self;
	while (simulation_running(monitor))
		usleep(MONITOR_WAIT);
	stop_everything(monitor);
	return (0);
}

int	execution(t_monitor *monitor)
{
	pthread_t	monitor_thread;

	list_foreach(monitor, pl_start);
	if (pthread_create(&monitor_thread, 0, monitoring, monitor) != 0)
		return (2);
	list_foreach(monitor, pl_join);
	pthread_join(monitor_thread, 0);
	free_ressources(monitor);
	return (0);
}
