/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:25:16 by erijania          #+#    #+#             */
/*   Updated: 2024/11/01 21:21:08 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"
#include <unistd.h>

int	pl_usleep(t_philo *pl, long ms)
{
	long	start;
	long	time;
	int		run;
	t_state	state;

	start = pl_timestamp();
	time = pl_timestamp();
	run = pl_is_running(pl);
	while (run && time < start + ms)
	{
		time = pl_timestamp();
		state = pl_get_state(pl);
		if (state == PHILO_FULL || state == PHILO_DEAD)
			return (0);
		if (pl->last_meal > 0 && pl->last_meal + pl->mon->tt.die < time)
		{
			pl_set_state(pl, PHILO_DEAD);
			return (0);
		}
		run = pl_is_running(pl);
	}
	return (run);
}
