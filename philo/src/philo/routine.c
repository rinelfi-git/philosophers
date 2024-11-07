/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/11/07 15:27:54 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_monitor.h"
#include "pl_types.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static int	do_eating(t_philo *philo)
{
	t_monitor	*monitor;
	int			out;

	monitor = philo->monitor;
	if (!philosopher_get_run(philo))
		return (0);
	if (monitor->size == 1)
		update_last_meal(philo);
	if (!do_take_fork(philo))
		return (0);
	philo->eat_times++;
	print_state(philo, "is eating");
	update_last_meal(philo);
	out = sleep_while(philo, monitor->time_to.eat);
	do_free_fork(philo);
	return (out);
}

static int	do_sleeping(t_philo *philo)
{
	t_monitor	*monitor;

	if (!philosopher_get_run(philo))
		return (0);
	monitor = philo->monitor;
	print_state(philo, "is sleeping");
	return (sleep_while(philo, monitor->time_to.sleep));
}

static int	do_thinking(t_philo *philo)
{
	int		interval;
	t_time	time_to;

	time_to = philo->monitor->time_to;
	if (!philosopher_get_run(philo))
		return (0);
	print_state(philo, "is thinking");
	interval = (time_to.die - (time_to.sleep + time_to.eat)) / 2;
	return (sleep_while(philo, interval));
}

void	*philosopher_routine(void *self)
{
	t_philo	*philo;

	philo = (t_philo *)self;
	if (philo->rank % 2 == 0)
		usleep(EVEN_WAIT_START);
	while (philosopher_get_run(philo))
	{
		if (!do_eating(philo))
			break ;
		if (!do_sleeping(philo))
			break ;
		if (!do_thinking(philo))
			break ;
	}
	philo->stop_job(philo);
	return (0);
}
