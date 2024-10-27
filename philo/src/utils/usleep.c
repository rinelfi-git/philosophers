/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:25:16 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 19:46:51 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"
#include <unistd.h>

int	pl_usleep(t_philo *pl, long ms)
{
	long	start;
	long	interval;
	long	timestamp;

	start = pl_utl_timestamp();
	timestamp = start;
	interval = start + ms;
	while (timestamp < interval)
	{
		timestamp = pl_utl_timestamp();
		if (pl->tt.die <= timestamp)
		{
			pl_set_state(pl, PHILO_DEAD);
			return (0);
		}
		usleep(EXEC_INTERVAL);
	}
	return (1);
}
