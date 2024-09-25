/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:51:53 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 19:31:22 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

void	pl_eat(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	pl->tt.sleep = tab->tt.sleep + time;
	pl->tt.think = tab->tt.think + time;
	pthread_mutex_unlock(&pl->time_lock);
}
