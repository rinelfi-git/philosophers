/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:25:16 by erijania          #+#    #+#             */
/*   Updated: 2024/10/26 17:59:17 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"
#include <unistd.h>

int	pl_usleep(t_philo *pl, long ms)
{
	long	start;
	long	timestamp;
	int		run;

	start = pl_utl_timestamp();
	timestamp = start;
	run = pl_is_running(pl);
	while (run && start + ms > timestamp)
	{
		timestamp = pl_utl_timestamp();
		run = pl_is_running(pl);
		if (pl->tt.die <= timestamp)
		{
			pl_set_state(pl, PHILO_DEAD);
			return (0);
		}
		usleep(EXEC_INTERVAL);
	}
	return (run);
}
