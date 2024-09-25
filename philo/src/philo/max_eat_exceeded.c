/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_eat_exceeded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:49:02 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 18:45:34 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"

int	is_max_eat_exceeded(t_philo *pl)
{
	t_table	*tab;
	int		exceeded;

	tab = pl->tab;
	pthread_mutex_lock(&tab->self_lock);
	exceeded = tab->max_eat && pl->max_eat > tab->max_eat;
	pthread_mutex_unlock(&tab->self_lock);
	return (exceeded);
}
