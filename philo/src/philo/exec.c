/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/10/10 20:39:49 by erijania         ###   ########.fr       */
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

static void	pl_print_state(t_philo *pl, t_state *curr, long time)
{
	char	*state_str;
	t_state	state;

	if (*curr == PHILO_DEAD || *curr == PHILO_FULL)
		return ;
	state = pl_get_state(pl);
	state_str = pl_str_state(state);
	if (state_str && *curr != state)
		pl_utl_message(pl, state_str, time);
	*curr = state;
}

static int	pl_should_eat(t_philo *pl, long time)
{
	t_state	state;

	state = pl_get_state(pl);
	if (pl_is_full(pl))
		return (0);
	if (state == PHILO_NONE)
		return (1);
	if (state == PHILO_THINKING && pl->tt.think <= time)
		return (1);
	return (0);
}

static void	init_routine(t_philo *pl, t_state *s)
{
	t_table	*tab;

	tab = pl->tab;
	pl->start = pl_utl_timestamp();
	pl->tt.die = tab->tt.die + pl->start;
	pl->tt.eat = tab->tt.eat + pl->start;
	pl->tt.sleep = tab->tt.sleep + pl->start;
	pl->tt.think = TT_THINK + pl->start;
	*s = PHILO_NONE;
}

void	*pl_exec(void *self)
{
	t_state	state;
	t_philo	*pl;
	long	time;
	int		wait;

	pl = to_philo(self);
	wait = (pl->tab->length - pl->rank) * 200; 
	wait += WAIT_START;
	if (pl->rank % 2 == 0)
		wait += EVEN_WAIT_START;
	usleep(wait);
	init_routine(pl, &state);
	while (pl_is_running(pl))
	{
		time = pl_utl_timestamp();
		pl_check_state(pl, time);
		if (pl_should_eat(pl, time))
			pl_take_fork(pl, time);
		pl_print_state(pl, &state, time);
		usleep(EXEC_INTERVAL);
	}
	pl->stop(pl, time);
	return (0);
}
