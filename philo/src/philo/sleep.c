/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:58:29 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 19:32:01 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_sleep(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	pl->tt.eat = tab->tt.eat + time;
	pl->tt.think = tab->tt.think + time;
	pthread_mutex_unlock(&pl->time_lock);
}
