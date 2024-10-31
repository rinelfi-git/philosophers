/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/10/31 19:47:25 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_monitor.h"
#include "pl_types.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

int	pl_eating(t_philo *pl)
{
	t_monitor	*tab;
	int			out;

	tab = pl->mon;
	pl->tt.die = tab->tt.die + pl_timestamp();
	out = 1;
	pl->max_eat++;
	pl_msg(pl, "is eating");
	if (!pl_usleep(pl, tab->tt.eat))
		out = 0;
	pl_free_fork(pl);
	return (out);
}

int	pl_sleeping(t_philo *pl)
{
	t_monitor	*tab;
	int			out;

	tab = pl->mon;
	out = 1;
	pl_msg(pl, "is sleeping");
	if (!pl_usleep(pl, tab->tt.sleep))
		out = 0;
	return (out);
}

int	pl_thinking(t_philo *pl)
{
	int	out;

	out = 1;
	pl_msg(pl, "is thinking");
	if (!pl_usleep(pl, 0))
		out = 0;
	return (out);
}

void	*pl_routine(void *self)
{
	t_philo	*pl;

	pl = (t_philo *)self;
	while (!pl_is_running(pl))
		usleep(WAIT_START);
	while (1)
	{
		if (!pl_take_fork(pl))
			break ;
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
