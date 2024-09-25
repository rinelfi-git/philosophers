/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 20:14:16 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_table.h"
#include "pl_philo.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	pl_start(t_table *tab)
{
	int		i;
	t_philo	*pl;

	i = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i++];
		pl->run(pl);
	}
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
	long	time;

	i = 0;
	time = pl_utl_timestamp();
	while (i < tab->length)
	{
		pl = &tab->philos[i++];
		pthread_mutex_lock(&pl->time_lock);
		stoped = (pl->tt.die + TT_THINK + 5) <= time
				|| is_max_eat_exceeded(pl);
		pthread_mutex_unlock(&pl->time_lock);
		if (stoped)
			return (0);
	}
	return (1);
}

static void	*monitoring(void *mon)
{
	t_table	*tab;
	int		sleep;

	usleep(WAIT_START);
	sleep = EXEC_INTERVAL / 2;
	tab = to_table(mon);
	while (!tab->dead && are_philos_alive(tab))
		usleep(sleep);
	pl_end(tab);
	return (0);
}

int	philosopher(t_table *tab)
{
	pthread_t	monitor;

	pl_start(tab);
	if (pthread_create(&monitor, 0, monitoring, tab) != 0)
		exit(1);
	pl_utl_lst_foreach(tab, pl_join);
	pthread_join(monitor, 0);
	pl_free(tab);
	return (0);
}
