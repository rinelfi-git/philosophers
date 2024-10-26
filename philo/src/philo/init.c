/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/10/26 18:00:53 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pl_table.h"
#include "pl_philo.h"
#include "pl_utils.h"
#include "pl_fork.h"

static void	pl_run(void *self)
{
	t_philo	*pl;

	pl = to_philo(self);
	if (pthread_create(&(pl->thread), 0, pl_exec, self) != 0)
		return ;
}

static void	pl_stop(void *self)
{
	t_philo	*pl;
	t_table	*tab;

	if (!self)
		return ;
	pl = to_philo(self);
	tab = pl->tab;
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
	pl->run = pl_run;
	pl->stop = pl_stop;
}
