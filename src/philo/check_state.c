/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 00:24:25 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_check_state(t_philo *pl, t_times *tt, long time)
{
	if (tt->eat >= time && pl->state == PHILO_EATING)
		pl_eat(pl, tt, time);
	else if (tt->sleep >= time && pl->state == PHILO_SLEEPING)
		pl_sleep(pl, tt, time);
	else
		pl_think(pl, tt, time);
	if (tt->die <= time || pl->max_eat > pl->seat->max_eat)
		pl->is_running = 0;
}
