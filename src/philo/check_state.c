/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 15:36:04 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_check_state(t_philo *pl)
{
	long	time;

	time = pl_utl_time();
	if (pl->state == PHILO_EATING && pl->tt.eat > time)
		pl_eat(pl, time);
	else if (pl->state == PHILO_SLEEPING && pl->tt.sleep > time)
		pl_sleep(pl, time);
	else
		pl_think(pl, time);
	if (pl->tt.die <= time || pl->max_eat > pl->seat->max_eat)
	{
		pl->is_running = 0;
		printf("%d is dying\n", pl->rank);
	}
}
