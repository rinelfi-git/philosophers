/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:25:16 by erijania          #+#    #+#             */
/*   Updated: 2024/11/07 15:19:58 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_monitor.h"
#include "pl_utils.h"
#include <unistd.h>

int	sleep_while(t_philo *philo, long ms)
{
	long	start_time;
	int		run;

	start_time = get_timestamp();
	run = philosopher_get_run(philo);
	while (run && get_timestamp() < start_time + ms)
	{
		usleep(EXEC_INTERVAL);
		run = philosopher_get_run(philo);
		if (!run)
			return (0);
	}
	return (1);
}
