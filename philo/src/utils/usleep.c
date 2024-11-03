/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:25:16 by erijania          #+#    #+#             */
/*   Updated: 2024/11/03 22:40:21 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_monitor.h"
#include "pl_utils.h"
#include <unistd.h>

int	pl_usleep(t_philo *pl, long ms)
{
	long	start;
	long	time;
	int		is_dead;

	start = pl_timestamp();
	time = pl_timestamp();
	while (time < start + ms)
	{
		usleep(EXEC_INTERVAL);
		time = pl_timestamp();
		is_dead = pl->last_meal > 0 && pl->last_meal + pl->mon->tt.die < time;
		if (is_dead)
		{
			pl_set_dead(pl->mon, pl);
			pl_set_run(pl, 0);
			return (0);
		}
		if (pl->mon->max_eat && pl->max_eat >= pl->mon->max_eat)
		{
			pl_set_state(pl, PHILO_FULL);
			return (0);
		}
	}
	return (1);
}
