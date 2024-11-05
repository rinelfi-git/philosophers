/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 14:55:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_monitor.h"
#include "pl_types.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static int	pl_eating(t_philo *philo)
{
	t_monitor	*monitor;
	int			out;

	monitor = philo->monitor;
	if (!pl_is_running(philo))
		return (0);
	if (monitor->size == 1)
		pl_update_last_meal(philo);
	if (!pl_take_fork(philo))
		return (0);
	philo->eat_times++;
	pl_msg(philo, "is eating");
	pl_update_last_meal(philo);
	out = pl_usleep(philo, monitor->time_to.eat);
	pl_free_fork(philo);
	return (out);
}

static int	pl_sleeping(t_philo *philo)
{
	t_monitor	*monitor;

	if (!pl_is_running(philo))
		return (0);
	monitor = philo->monitor;
	pl_msg(philo, "is sleeping");
	return (pl_usleep(philo, monitor->time_to.sleep));
}

static int	pl_thinking(t_philo *philo)
{
	int		interval;
	t_time	time_to;

	time_to = philo->monitor->time_to;
	if (!pl_is_running(philo))
		return (0);
	pl_msg(philo, "is thinking");
	interval = (time_to.die - (time_to.sleep + time_to.eat)) / 2;
	return (pl_usleep(philo, interval));
}

void	*pl_routine(void *self)
{
	t_philo	*philo;

	philo = (t_philo *)self;
	if (philo->rank % 2 == 0)
		usleep(EVEN_WAIT_START);
	while (pl_is_running(philo))
	{
		if (!pl_eating(philo))
			break ;
		if (!pl_sleeping(philo))
			break ;
		if (!pl_thinking(philo))
			break ;
	}
	philo->stop_job(philo);
	return (0);
}
