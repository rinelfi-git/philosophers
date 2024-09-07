/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:49:27 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 11:55:01 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_set_times(t_philo *pl, int *times)
{
	pl->tt.die = times[0];
	pl->tt.eat = times[1];
	pl->tt.sleep = times[2];
}
