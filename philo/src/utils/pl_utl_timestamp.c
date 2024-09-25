/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utl_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:09:39 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 17:49:32 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	pl_utl_timestamp(void)
{
	long			timestamp;
	struct timeval	time;

	gettimeofday(&time, 0);
	timestamp = time.tv_usec / 1000;
	timestamp = time.tv_sec * 1000 + timestamp;
	return (timestamp);
}
