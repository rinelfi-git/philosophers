/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/10/09 17:47:40 by erijania         ###   ########.fr       */
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
	pl->is_running = 1;
	if (pthread_create(&(pl->thread), 0, pl_exec, self) != 0)
		exit(2);
}

static void	pl_stop(void *self)
{
	t_philo	*pl;
	t_table	*tab;
	long	time;

	if (!self)
		return ;
	pl = to_philo(self);
	time = pl_utl_timestamp();
	pthread_mutex_lock(&pl->self_lock);
	pl->is_running = 0;
	pthread_mutex_unlock(&pl->self_lock);
	tab = pl->tab;
	pl_free_fork(pl);
	if ((pl->tt.die + ROOM) <= time)
	{
		pl->state = PHILO_DEAD;
		pthread_mutex_lock(&tab->dead_lock);
		if (!tab->dead)
		{
			tab->dead = pl;
			pl_utl_message(pl, "died", time);
		}
		pthread_mutex_unlock(&tab->dead_lock);
	}
}

void	init_philo(t_philo *pl, int id, t_fork *left)
{
	pthread_mutex_init(&pl->self_lock, 0);
	pthread_mutex_init(&pl->time_lock, 0);
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
