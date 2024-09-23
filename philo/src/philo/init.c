/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/23 20:12:19 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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
	pthread_create(&(pl->thread), 0, pl_exec, self);
}

static void	pl_stop(void *self)
{
	t_philo	*pl;
	t_table	*tab;
	long	time;

	pl = to_philo(self);
	time = pl_utl_time();
	pl->is_running = 0;
	tab = pl->tab;
	pl->state = PHILO_DEAD;
	pl_free_fork(pl);
	if (pl->tt.die <= time)
	{
		pthread_mutex_lock(&tab->dead_lock);
		if (!tab->dead)
		{
			tab->dead = pl;
			printf("%ld %d died\n", time - tab->start, pl->id);
		}
		pl_end(pl->tab);
		pthread_mutex_unlock(&tab->dead_lock);
	}
}

void	init_philo(t_philo *pl, int id, t_fork *left)
{
	pl->id = id;
	pl->rank = id + 1;
	pl->tt.die = 0;
	pl->tt.eat = 0;
	pl->tt.sleep = 0;
	pl->left = left;
	pl->right = 0;
	pl->is_running = 0;
	pl->max_eat = 0;
	pl->state = PHILO_NONE;
	pl->tab = 0;
	pl->run = pl_run;
	pl->stop = pl_stop;
}
