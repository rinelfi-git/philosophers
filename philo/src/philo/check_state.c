/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 22:43:15 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_check_state(t_philo *pl, long time)
{
	if (pl->state == PHILO_EATING)
		pl_eat(pl, time);
	else if (pl->state == PHILO_SLEEPING && pl->tt.sleep > time)
		pl_sleep(pl, time);
	else
		pl_think(pl, time);
}
