/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utl_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:09:39 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 11:33:23 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	pl_utl_time(void)
{
	long			timestamp;
	long			multiplier;
	struct timeval	time;

	gettimeofday(&time, 0);
	multiplier = 1;
	timestamp = time.tv_usec / 1000;
	while (timestamp / multiplier > 0)
		multiplier *= 10;
	timestamp = time.tv_sec * multiplier + timestamp;
	return (timestamp);
}
