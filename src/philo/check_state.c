/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 14:06:35 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_check_state(t_philo *pl)
{
	long	time;

	time = pl_utl_time();
	printf("TEST\n");
	if (pl->state == PHILO_EATING)
		pl_eat(pl, time);
	else if (pl->state == PHILO_SLEEPING)
		pl_sleep(pl, time);
	else
		pl_think(pl, time);
	if (pl->tt.die <= time || pl->max_eat > pl->seat->max_eat)
		pl->is_running = 0;
}
