/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:49:27 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 13:01:42 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_set_times(void *pl, int *times)
{
	to_philo(pl)->tt.die = times[0];
	to_philo(pl)->tt.eat = times[1];
	to_philo(pl)->tt.sleep = times[2];
}
