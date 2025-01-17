/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:06:03 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 15:14:27 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_monitor.h"
#include "pl_utils.h"
#include <unistd.h>

void	stop_everything(t_monitor *monitor)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < monitor->size)
		philosopher_set_run(&monitor->philosopher_list[i], 0);
	philo = monitor_get_dead(monitor);
	if (philo)
		print_state(philo, "died");
}

static void	mutex_monitor_destroy(t_monitor *monitor)
{
	pthread_mutex_destroy(&monitor->dead_lock);
	pthread_mutex_destroy(&monitor->print_lock);
}

static void	mutex_philosopher_destroy(t_philo *philo)
{
	pthread_mutex_destroy(&philo->state_lock);
	pthread_mutex_destroy(&philo->run_lock);
	pthread_mutex_destroy(&philo->last_meal_lock);
}

void	free_ressources(t_monitor *monitor)
{
	int		i;
	t_sync	*fork;
	t_philo	*philo;

	i = 0;
	while (i < monitor->size)
	{
		philo = &monitor->philosopher_list[i];
		fork = &monitor->fork_list[i++];
		mutex_philosopher_destroy(philo);
		pthread_mutex_destroy(fork);
	}
	mutex_monitor_destroy(monitor);
	free(monitor->fork_list);
	free(monitor->philosopher_list);
}
