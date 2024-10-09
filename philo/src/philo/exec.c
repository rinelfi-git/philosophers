/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/10/09 17:52:28 by erijania         ###   ########.fr       */
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

	state_str = pl_str_state(pl->state);
	if (state_str)
	{
		pl_utl_message(pl, state_str, time);
		*curr = pl->state;
	}
}

static int	pl_should_eat(t_philo *pl, long time)
{
	if (is_max_eat_exceeded(pl))
		return (0);
	if (pl->state == PHILO_NONE)
		return (1);
	if (pl->state == PHILO_THINKING && pl->tt.think <= time)
		return (1);
	return (0);
}

static void	init_routine(t_philo *pl, t_state *s, int *r)
{
	t_table	*tab;

	tab = pl->tab;
	pl->start = pl_utl_timestamp();
	pthread_mutex_lock(&pl->time_lock);
	pl->tt.die = tab->tt.die + pl->start;
	pl->tt.eat = tab->tt.eat + pl->start;
	pl->tt.sleep = tab->tt.sleep + pl->start;
	pl->tt.think = TT_THINK + pl->start;
	pthread_mutex_unlock(&pl->time_lock);
	*s = PHILO_NONE;
	*r = 1;
}

void	*pl_exec(void *self)
{
	t_state	state;
	t_philo	*pl;
	int		running;
	long	time;

	pl = to_philo(self);
	usleep(pl->tab->length - pl->rank);
	if (pl->rank % 2 == 0)
		usleep(EVEN_WAIT_START);
	init_routine(pl, &state, &running);
	while (running)
	{
		time = pl_utl_timestamp();
		pl_check_state(pl, time);
		if (pl_should_eat(pl, time))
			pl_take_fork(pl, time);
		if (is_max_eat_exceeded(pl) || (pl->tt.die + ROOM) <= time)
			pl->stop(pl);
		if (state != pl->state)
			pl_print_state(pl, &state, time);
		pthread_mutex_lock(&pl->self_lock);
		running = pl->is_running;
		pthread_mutex_unlock(&pl->self_lock);
		usleep(EXEC_INTERVAL);
	}
	return (0);
}
