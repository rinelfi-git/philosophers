/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/09/17 22:55:46 by erijania         ###   ########.fr       */
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

static void	pl_print_state(t_philo *pl, t_state *curr)
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

void	*pl_exec(void *self)
{
	t_state	state;
	long	time;
	t_philo	*pl;

	pl = to_philo(self);
	while (to_philo(self)->is_running)
	{
		time = pl_utl_time();
		pl_check_state(pl, time);
		if (pl->state == PHILO_NONE || pl->state == PHILO_THINKING)
			pl_take_fork(pl);
		if (pl->tt.eat <= time || (pl->tt.free <= time && pl_has_one_fork(pl)))
			pl_free_fork(pl);
		if (is_max_eat_exceeded(pl) || pl->tt.die <= time)
			pl->stop(self);
		if (state != pl->state)
			pl_print_state(pl, &state);
		usleep(EXEC_INTERVAL);
	}
	return (0);
}
