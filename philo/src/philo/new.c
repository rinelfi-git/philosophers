/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/23 17:57:58 by erijania         ###   ########.fr       */
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
	t_philo	*philo;

	philo = to_philo(self);
	philo->is_running = 1;
	pthread_create(&philo->pt, 0, pl_exec, philo);
}

static void	pl_stop(void *self)
{
	t_philo	*pl;
	t_table	*tab;
	long	time;

	pl = to_philo(self);
	time = pl_utl_time();
	pl->is_running = 0;
	tab = pl->seat;
	pl_free_fork(pl);
	if (pl->tt.die <= time)
	{
		pthread_mutex_lock(&tab->dead_lock);
		if (!tab->dead)
		{
			pl->state = PHILO_DEAD;
			tab->dead = pl;
			printf("%ld %d died\n", time - tab->start, pl->rank);
		}
		pl_end(pl->seat);
		pthread_mutex_unlock(&tab->dead_lock);
	}
}

t_philo	*new_philo(int rank, t_fork *left)
{
	t_philo	*ret;

	ret = (t_philo *)malloc(sizeof(t_philo));
	if (!ret)
		exit(1);
	ret->id = rank;
	ret->rank = rank + 1;
	ret->tt.die = 0;
	ret->tt.eat = 0;
	ret->tt.sleep = 0;
	ret->left = left;
	ret->right = 0;
	ret->is_running = 0;
	ret->max_eat = 0;
	ret->state = PHILO_NONE;
	ret->seat = 0;
	ret->run = pl_run;
	ret->stop = pl_stop;
	return (ret);
}
