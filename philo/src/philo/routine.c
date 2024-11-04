/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 20:40:38 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_monitor.h"
#include "pl_types.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static int	pl_eating(t_philo *pl)
{
	t_monitor	*mon;
	int			out;
	long		last_meal;
	
	mon = pl->mon;
	if (!pl_is_running(pl))
		return (0);
	last_meal = pl_get_last_meal(pl);
	if (last_meal > 0 && last_meal + mon->tt.die <= pl_timestamp())
		return (0);
	if (mon->length == 1)
		pl_update_last_meal(pl);
	if (!pl_take_fork(pl))
		return (0);
	pl->max_eat++;
	pl_update_last_meal(pl);
	pl_msg(pl, "is eating");
	out = pl_usleep(pl, mon->tt.eat);
	pl_free_fork(pl);
	return (out);
}

static int	pl_sleeping(t_philo *pl)
{
	t_monitor	*mon;

	if (!pl_is_running(pl))
		return (0);
	mon = pl->mon;
	pl_msg(pl, "is sleeping");
	return (pl_usleep(pl, mon->tt.sleep));
}

static int	pl_thinking(t_philo *pl)
{
	t_monitor	*mon;
	int			interval;

	mon = pl->mon;
	if (!pl_is_running(pl))
		return (0);
	pl_msg(pl, "is thinking");
	interval = mon->tt.die - (mon->tt.eat + mon->tt.sleep);
	if (interval < 0)
		interval = 0;
	return (pl_usleep(pl, interval / 2));
}

void	*pl_routine(void *self)
{
	t_philo	*pl;

	pl = (t_philo *)self;
	if (pl->rank % 2 == 0)
		usleep(EVEN_WAIT_START);
	while (pl_is_running(pl))
	{
		if (!pl_eating(pl))
			break ;
		if (!pl_sleeping(pl))
			break ;
		if (!pl_thinking(pl))
			break ;
	}
	pl->stop(pl);
	return (0);
}
