/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 08:43:53 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_check_state(t_philo *pl, t_times *tt)
{
	if (pl->state == PHILO_EATING && tt->eat)
		pl_eat(pl, tt);
	else if (pl->state == PHILO_SLEEPING && tt->sleep)
		pl_sleep(pl, tt);
	else
		pl_think(pl, tt);
	if (!tt->die || pl->max_eat > pl->seat->max_eat)
		pl->is_running = 0;
}
