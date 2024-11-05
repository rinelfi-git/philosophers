/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 14:51:16 by erijania         ###   ########.fr       */
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
	if (pthread_create(&philo->thread, 0, pl_routine, philo) != 0)
		return ;
}

static int	nobodys_dead(t_monitor *monitor)
{
	int		i;
	t_state	state;
	t_philo	*philo;
	long	times[2];

	i = 0;
	monitor->ate_number = 0;
	times[0] = pl_timestamp();
	while (i < monitor->size)
	{
		philo = &monitor->philosopher_list[i++];
		state = pl_get_state(philo);
		times[1] = pl_get_last_meal(philo);
		if (state == PHILO_FULL)
			monitor->ate_number++;
		else if (times[1] > 0 && times[1] + monitor->time_to.die <= times[0])
		{
			pl_set_run(philo, 0);
			pl_set_dead(monitor, philo);
			return (0);
		}
	}
	return (monitor->ate_number < monitor->size);
}

static void	*monitoring(void *self)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)self;
	while (nobodys_dead(monitor))
		usleep(MONITOR_WAIT);
	pl_end(monitor);
	return (0);
}

int	philosopher(t_monitor *monitor)
{
	pthread_t	monitor_thread;

	pl_utl_lst_foreach(monitor, pl_start);
	if (pthread_create(&monitor_thread, 0, monitoring, monitor) != 0)
		return (2);
	pl_utl_lst_foreach(monitor, pl_join);
	pthread_join(monitor_thread, 0);
	printf("FREE\n");
	pl_free(monitor);
	return (0);
}
