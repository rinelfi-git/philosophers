/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 01:06:59 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_check_state(t_philo *pl, t_times *tt, long time)
{
	if (pl->state == PHILO_EATING && tt->eat > time)
		pl_eat(pl, tt, time);
	else if (pl->state == PHILO_SLEEPING && tt->sleep > time)
		pl_sleep(pl, tt, time);
	else
		pl_think(pl, tt, time);
	if (tt->die <= time || pl->max_eat > pl->seat->max_eat)
		pl->is_running = 0;
}
