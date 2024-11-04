/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 20:02:15 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_monitor.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static void	pl_stop(void *self)
{
	t_philo	*pl;

	if (!self)
		return ;
	pl = (t_philo *)self;
	pl_set_run(pl, 0);
}

void	init_philo(t_philo *pl, int id, t_sync *left)
{
	pthread_mutex_init(&pl->state_lock, 0);
	pthread_mutex_init(&pl->run_lock, 0);
	pthread_mutex_init(&pl->last_meal_lock, 0);
	pl->rank = id + 1;
	pl->tt.die = 1;
	pl->tt.eat = 1;
	pl->tt.sleep = 1;
	pl->left = left;
	pl->right = 0;
	pl->is_running = 0;
	pl->max_eat = 0;
	pl->last_meal = 0;
	pl->taken_fork = 0;
	pl->state = PHILO_NONE;
	pl->mon = 0;
	pl->stop = pl_stop;
}
