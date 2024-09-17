/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/09/17 19:53:40 by erijania         ###   ########.fr       */
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

	state = PHILO_THINKING;
	pl_print_state(to_philo(self), &state);
	while (to_philo(self)->is_running)
	{
		time = pl_utl_time();
		pl_check_state(to_philo(self), time);
		if (to_philo(self)->state == PHILO_THINKING)
			pl_take_fork(to_philo(self));
		else if (to_philo(self)->tt.eat <= time)
			pl_free_fork(to_philo(self));
		if (is_max_eat_exceeded(to_philo(self)) || to_philo(self)->tt.die <= time)
			to_philo(self)->stop(self);
		if (state != to_philo(self)->state)
			pl_print_state(to_philo(self), &state);
		usleep(EXEC_INTERVAL);
	}
	return (0);
}
