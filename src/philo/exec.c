/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 01:02:13 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"
#include "pl_table.h"
#include <unistd.h>
#include <stdlib.h>

static char	*pl_str_state(t_pl_state state)
{
	if (state == PHILO_EATING)
		return ("is eating");
	if (state == PHILO_SLEEPING)
		return ("is sleeping");
	if (state == PHILO_THINKING)
		return ("is thinking");
	return ("died");
}

static void	pl_refresh_state(t_philo *pl, t_pl_state *curr)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < pl->seat->length)
	{
		philo = pl->seat->philos[i++];
		if (philo->state == PHILO_DEAD && pl != philo)
			return ;
	}
	printf("%ld %d %s\n", pl_utl_time(), pl->rank + 1, pl_str_state(pl->state));
	*curr = pl->state;
}

static void	init_counter(t_times *out, t_times *in)
{
	long	time;

	time = pl_utl_time();
	out->die = in->die + time;
	out->eat = in->eat + time;
	out->sleep = in->sleep + time;
}

void	*pl_exec(void *self)
{
	t_philo		*pl;
	t_pl_state	state;
	t_times		tt;
	long		time;

	pl = to_philo(self);
	state = PHILO_THINKING;
	init_counter(&tt, &pl->tt);
	pl_refresh_state(pl, &state);
	while (pl->is_running)
	{
		time = pl_utl_time();
		if (pl->state == PHILO_THINKING)
			pl_take_fork(pl, time);
		else if (tt.eat <= time)
			pl_free_fork(pl);
		pl_check_state(pl, &tt, time);
		if (tt.die <= time)
			pl->state = PHILO_DEAD;
		if (state != pl->state)
			pl_refresh_state(pl, &state);
		usleep(1000);
	}
	pl_stop(pl->seat);
	return (0);
}
