/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/10/11 08:38:26 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_table.h"
#include "pl_philo.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	*pl_start(void *self)
{
	int		i;
	t_philo	*pl;
	t_table	*tab;

	tab = to_table(self);
	i = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i++];
		pl->run(pl);
	}
	return (0);
}

static void	pl_join(void *self)
{
	t_philo	*pl;

	pl = to_philo(self);
	pthread_join(pl->thread, 0);
}

static int	are_philos_alive(t_table *tab)
{
	int		i;
	int		stoped;
	t_philo	*pl;

	i = 0;

	while (i < tab->length - 1)
	{
		pl = &tab->philos[i++];
		stoped = 0;
		pthread_mutex_lock(&pl->state_lock);
		stoped = pl->state == PHILO_DEAD || pl->state == PHILO_FULL;
		pthread_mutex_unlock(&pl->state_lock);
		if (stoped)
			return (0);
	}
	return (1);
}

static void	*monitoring(void *mon)
{
	t_table	*tab;
	int		i;
	t_philo	*pl;

	usleep(WAIT_START);
	tab = to_table(mon);
	i = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i];
		i += 2;
		pl_set_run(pl, 1);
	}
	usleep(EVEN_WAIT_START * 1000);
	i = 1;
	while (i < tab->length)
	{
		pl = &tab->philos[i];
		i += 2;
		pl_set_run(pl, 1);
	}
	while (!pl_get_dead(tab) && are_philos_alive(tab))
		usleep(MONITOR_WAIT);
	pl_end(tab);
	return (0);
}

int	philosopher(t_table *tab)
{
	pthread_t	monitor;
	pthread_t	start;

	if (pthread_create(&start, 0, pl_start, tab) != 0)
		exit(2);
	pthread_join(start, 0);
	if (pthread_create(&monitor, 0, monitoring, tab) != 0)
		exit(2);
	pl_utl_lst_foreach(tab, pl_join);
	pthread_join(monitor, 0);
	pl_free(tab);
	return (0);
}
