/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:49:06 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 14:15:11 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_free_fork(t_philo *pl)
{
	int		i;
	t_fork	*fork;	

	i = 0;
	while (i < 2)
	{
		fork = to_fork(pl->forks[i]);
		fork->user = 0;
		pthread_mutex_unlock(&fork->mt);
		pl->forks[i] = 0;
		i++;
	}
	pl->state = PHILO_SLEEPING;
}
