/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_full.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:49:02 by erijania          #+#    #+#             */
/*   Updated: 2024/10/10 06:54:52 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"

int	pl_is_full(t_philo *pl)
{
	int		exceeded;

	exceeded = 0;
	pthread_mutex_lock(&pl->state_lock);
	exceeded = pl->state == PHILO_FULL;
	pthread_mutex_unlock(&pl->state_lock);
	return (exceeded);
}
