/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 20:40:22 by erijania         ###   ########.fr       */
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
	pl->is_running = 1;
	if (pthread_create(&pl->thread, 0, pl_routine, pl) != 0)
		return ;
}

static int	nobodys_dead(t_monitor *mon)
{
	int		i;
	t_state	state;
	t_philo	*pl;
	long	times[2];

	i = 0;
	mon->nbr_ate = 0;
	times[0] = pl_timestamp();
	while (i < mon->length)
	{
		pl = &mon->philos[i++];
		state = pl_get_state(pl);
		times[1] = pl_get_last_meal(pl);
		if (state == PHILO_FULL)
			mon->nbr_ate++;
		else if (times[1] > 0 && times[1] + mon->tt.die <= times[0])
		{
			pl_set_run(pl, 0);
			pl_set_dead(mon, pl);
			pl_msg(pl, "died");
			return (0);
		}
	}
	return (mon->nbr_ate < mon->length);
}

static void	*monitoring(void *self)
{
	t_monitor	*mon;

	mon = (t_monitor *)self;
	while (nobodys_dead(mon))
		usleep(MONITOR_WAIT);
	pl_end(mon);
	return (0);
}

int	philosopher(t_monitor *mon)
{
	pthread_t	monitor;

	pl_utl_lst_foreach(mon, pl_start);
	if (pthread_create(&monitor, 0, monitoring, mon) != 0)
		return (2);
	pl_utl_lst_foreach(mon, pl_join);
	pthread_join(monitor, 0);
	pl_free(mon);
	return (0);
}
