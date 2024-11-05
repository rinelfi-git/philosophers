/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 16:18:21 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_monitor.h"
#include "pl_philo.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static void	stop_job(void *self)
{
	t_philo	*pl;

	if (!self)
		return ;
	pl = (t_philo *)self;
	philosopher_set_run(pl, 0);
}

void	philosopher_init(t_philo *pl, int id, t_sync *left)
{
	pthread_mutex_init(&pl->state_lock, 0);
	pthread_mutex_init(&pl->run_lock, 0);
	pthread_mutex_init(&pl->last_meal_lock, 0);
	pl->rank = id + 1;
	pl->left_fork = left;
	pl->right_fork = 0;
	pl->is_running = 0;
	pl->eat_times = 0;
	pl->last_meal = 0;
	pl->taken_fork = 0;
	pl->state = PHILO_NONE;
	pl->monitor = 0;
	pl->stop_job = stop_job;
}
