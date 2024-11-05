/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:28:05 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 15:07:50 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_philo.h"

t_philo	*monitor_get_dead(t_monitor *monitor)
{
	t_philo	*philo;

	philo = 0;
	pthread_mutex_lock(&monitor->dead_lock);
	philo = monitor->dead;
	pthread_mutex_unlock(&monitor->dead_lock);
	return (philo);
}

void	monitor_set_dead(t_monitor *monitor, t_philo *philo)
{
	pthread_mutex_lock(&monitor->dead_lock);
	monitor->dead = philo;
	pthread_mutex_unlock(&monitor->dead_lock);
	set_philo_state(philo, PHILO_DEAD);
}
