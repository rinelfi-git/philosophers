/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 15:24:01 by erijania         ###   ########.fr       */
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
	return ("is dead");
}

static void	pl_refresh_state(t_philo *pl, t_pl_state *curr)
{
	printf("%ld %d %s\n", pl_utl_time(), pl->rank + 1, pl_str_state(pl->state));
	*curr = pl->state;
}

void	*pl_exec(void *self)
{
	t_philo		*pl;
	t_pl_state	curr_state;
	t_times		tt;

	pl = to_philo(self);
	curr_state = PHILO_SLEEPING;
	tt = pl->tt;
	while (tt.die && pl->is_running)
	{
		if (curr_state != pl->state)
			pl_refresh_state(pl, &curr_state);
		pl_check_state(pl, &tt);
		if (pl->state == PHILO_THINKING)
			pl_take_fork(pl);
		else if (tt.eat <= 0)
			pl_free_fork(pl);
		usleep(1000);
	}
	if (!tt.die)
	{
		printf("%ld %d died\n", pl_utl_time(), pl->rank + 1);
		pl_free(pl);
	}
	exit(0);
	return (0);
}
