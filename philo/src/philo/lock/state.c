/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:23:47 by erijania          #+#    #+#             */
/*   Updated: 2024/10/10 18:34:56 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"

t_state	pl_get_state(t_philo *pl)
{
	t_state	state;
	
	pthread_mutex_lock(&pl->state_lock);
	state = pl->state;
	pthread_mutex_unlock(&pl->state_lock);
	return (state);
}

void	pl_set_state(t_philo *pl, t_state state)
{
	pthread_mutex_lock(&pl->state_lock);
	pl->state = state;
	pthread_mutex_unlock(&pl->state_lock);
}
