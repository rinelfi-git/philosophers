/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 19:32:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_check_state(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	if (pl->state == PHILO_EATING)
		pl_eat(pl, time);
	else if (pl->state == PHILO_SLEEPING && pl->tt.sleep > time)
		pl_sleep(pl, time);
	else if (pl->state == PHILO_NONE)
	{
		pthread_mutex_lock(&pl->time_lock);
		pl->tt.sleep = tab->tt.sleep + time;
		pl->tt.eat = tab->tt.eat + time;
		pl->tt.think = tab->tt.think + time;
		pthread_mutex_unlock(&pl->time_lock);
	}
	else
		pl_think(pl, time);
}
