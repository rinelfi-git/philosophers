/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 23:59:01 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_monitor.h"
#include "pl_philo.h"
#include "pl_types.h"
#include "pl_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	pl_join(void *self)
{
	t_philo	*pl;

	pl = (t_philo *)self;
	pthread_join(pl->thread, 0);
}

static void	pl_start(void *self)
{
	t_philo	*pl;

	pl = (t_philo *)self;
	if (pthread_create(&pl->thread, 0, pl_routine, pl) != 0)
		return ;
}

static int	nobodys_dead(t_monitor *tab)
{
	int		i;
	t_state	state;
	int		fulls;
	t_philo	*pl;

	i = 0;
	fulls = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i++];
		state = pl_get_state(pl);
		if (state == PHILO_FULL)
			fulls++;
		else if (state == PHILO_DEAD)
		{
			pl_set_dead(tab, pl);
			pl_msg(pl, "died");
			return (0);
		}
	}
	return (fulls < tab->length);
}

static void	*monitoring(void *mon)
{
	t_monitor	*tab;
	int			i;
	t_philo		*pl;

	usleep(WAIT_START);
	tab = to_monitor(mon);
	i = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i];
		i += 2;
		pl_set_run(pl, 1);
	}
	usleep(EVEN_WAIT_START);
	i = 1;
	while (i < tab->length)
	{
		pl = &tab->philos[i];
		i += 2;
		pl_set_run(pl, 1);
	}
	while (nobodys_dead(tab))
		usleep(MONITOR_WAIT);
	pl_end(tab);
	return (0);
}

int	philosopher(t_monitor *tab)
{
	pthread_t	monitor;

	pl_utl_lst_foreach(tab, pl_start);
	if (pthread_create(&monitor, 0, monitoring, tab) != 0)
		return (2);
	pl_utl_lst_foreach(tab, pl_join);
	pthread_join(monitor, 0);
	pl_free(tab);
	return (0);
}
