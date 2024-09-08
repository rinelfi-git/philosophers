/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 14:03:48 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"
#include "pl_utils.h"
#include "pl_table.h"
#include <unistd.h>
#include <stdlib.h>

static char	*pl_str_state(t_state state)
{
	if (state == PHILO_EATING)
		return ("is eating");
	if (state == PHILO_SLEEPING)
		return ("is sleeping");
	if (state == PHILO_THINKING)
		return ("is thinking");
	return ("died");
}

static void	pl_refresh_state(t_philo *pl, t_state *curr)
{
	t_table	*tab;
	long	interval;

	tab = pl->seat;
	interval = pl_utl_time() - tab->start;
	if (!tab->dead || pl == tab->dead)
	{
		printf("%ld %d %s\n", interval, pl->rank, pl_str_state(pl->state));
		*curr = pl->state;
	}
}

static void	pl_kill(t_philo *pl)
{
	pthread_mutex_lock(&pl->seat->lock);
	pl->seat->dead = pl;
	pl->state = PHILO_DEAD;
	pthread_mutex_unlock(&pl->seat->lock);
}

void	*pl_exec(void *self)
{
	t_philo	*pl;
	t_state	state;
	long	time;

	pl = to_philo(self);
	state = PHILO_THINKING;
	pl_refresh_state(pl, &state);
	while (!pl->seat->dead)
	{
		time = pl_utl_time();
		pl_check_state(pl);
		if (pl->state == PHILO_THINKING)
			pl_take_fork(pl);
		else if (pl->tt.eat <= time)
			pl_free_fork(pl);
		if (pl->tt.die <= time)
			pl_kill(pl);
		if (state != pl->state)
			pl_refresh_state(pl, &state);
		usleep(EXEC_INTERVAL);
	}
	pl_stop(pl->seat);
	return (0);
}
