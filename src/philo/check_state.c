/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 15:03:19 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_check_state(t_philo *pl, t_times *tt)
{
	if (tt->eat && pl->state == PHILO_EATING)
		pl_eat(pl, tt);
	else if (tt->sleep && pl->state == PHILO_SLEEPING)
		pl_sleep(pl, tt);
	else
		pl_think(pl, tt);
}
