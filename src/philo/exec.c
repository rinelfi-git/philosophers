/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 12:32:02 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"
#include "pl_utils.h"
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

void	*pl_exec(void *self)
{
	t_philo	*pl;
	t_state	state;

	pl = to_philo(self);
	state = PHILO_THINKING;
	pl_refresh_state(pl, &state);
	while (pl->is_running)
	{
		pl_check_state(pl, &tt);
		if (pl->state == PHILO_THINKING)
			pl_take_fork(pl);
		else if (tt.eat <= 0)
			pl_free_fork(pl);
		if (tt.die <= 0)
			pl->state = PHILO_DEAD;
		if (state != pl->state)
			pl_refresh_state(pl, &state);
		usleep(EXEC_INTERVAL);
	}
	pl_stop(pl->seat);
	return (0);
}
