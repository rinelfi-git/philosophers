/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 23:38:56 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_fork.h"
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
	pl_free_fork(pl);
}

void	init_philo(t_philo *pl, int id, t_fork *left)
{
	pthread_mutex_init(&pl->self_lock, 0);
	pthread_mutex_init(&pl->time_lock, 0);
	pthread_mutex_init(&pl->state_lock, 0);
	pthread_mutex_init(&pl->run_lock, 0);
	pl->id = id;
	pl->rank = id + 1;
	pl->tt.die = 1;
	pl->tt.eat = 1;
	pl->tt.sleep = 1;
	pl->left = left;
	pl->right = 0;
	pl->is_running = 0;
	pl->max_eat = 0;
	pl->state = PHILO_NONE;
	pl->tab = 0;
	pl->stop = pl_stop;
}
