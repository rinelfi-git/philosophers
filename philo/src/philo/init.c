/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/11/07 15:19:02 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_monitor.h"
#include "pl_philo.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static void	stop_job(void *self)
{
	t_philo	*philo;

	if (!self)
		return ;
	philo = (t_philo *)self;
	philosopher_set_run(philo, 0);
}

void	philosopher_init(t_philo *philo, int id, t_sync *left)
{
	pthread_mutex_init(&philo->state_lock, 0);
	pthread_mutex_init(&philo->run_lock, 0);
	pthread_mutex_init(&philo->last_meal_lock, 0);
	philo->rank = id + 1;
	philo->left_fork = left;
	philo->right_fork = 0;
	philo->is_running = 0;
	philo->eat_times = 0;
	philo->last_meal = 0;
	philo->taken_fork = 0;
	philo->state = PHILO_NONE;
	philo->monitor = 0;
	philo->stop_job = stop_job;
}
