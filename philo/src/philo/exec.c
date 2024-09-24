/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/09/24 20:08:53 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
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
	return (0);
}

static void	pl_print_state(t_philo *pl, t_state *curr)
{
	t_table	*tab;
	long	interval;
	char	*state_str;

	tab = pl->tab;
	interval = pl_utl_time() - tab->start;
	state_str = pl_str_state(pl->state);
	if (state_str)
	{
		printf("%ld %d %s\n", interval, pl->rank, state_str);
		*curr = pl->state;
	}
}

static int	pl_should_eat(t_philo *pl)
{
	long	time;

	if (!pl->is_running)
		return (0);
	if (is_max_eat_exceeded(pl))
		return (0);
	if (pl->state == PHILO_NONE)
		return (1);
	time = pl_utl_time();
	if (pl->state == PHILO_THINKING && pl->tt.think <= time)
		return (1);
	return (0);
}

void	*pl_exec(void *self)
{
	t_state	state;
	long	time;
	t_philo	*pl;

	pl = to_philo(self);
	state = PHILO_NONE;
	if (pl->rank % 2 == 0)
		usleep(EVEN_WAIT_START);
	usleep(WAIT_START);
	while (pl->is_running)
	{
		time = pl_utl_time();
		pl_check_state(pl, time);
		if (pl_should_eat(pl))
			pl_take_fork(pl);
		if (pl->tt.eat <= time)
			pl_free_fork(pl);
		if (is_max_eat_exceeded(pl) || pl->tt.die <= time)
			pl->stop(self);
		if (state != pl->state)
			pl_print_state(pl, &state);
		usleep(EXEC_INTERVAL);
	}
	return (0);
}
