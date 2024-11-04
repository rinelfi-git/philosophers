/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:04:22 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 09:38:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

long	pl_get_last_meal(t_philo *pl)
{
	long	last_meal;

	pthread_mutex_lock(&pl->last_meal_lock);
	last_meal = pl->last_meal;
	pthread_mutex_unlock(&pl->last_meal_lock);
	return (last_meal);
}

void	pl_update_last_meal(t_philo *pl)
{
	pthread_mutex_lock(&pl->last_meal_lock);
	pl->last_meal = pl_timestamp();
	pthread_mutex_unlock(&pl->last_meal_lock);
}
