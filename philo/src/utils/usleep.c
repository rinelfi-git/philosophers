/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:25:16 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 22:44:31 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_monitor.h"
#include "pl_utils.h"
#include <unistd.h>

int	pl_usleep(t_philo *pl, long ms)
{
	long	start;
	int		run;

	start = pl_timestamp();
	run = pl_is_running(pl);
	while (run && pl_timestamp() < start + ms)
	{
		run = pl_is_running(pl);
		if (!run)
			return (0);
	}
	return (1);
}
