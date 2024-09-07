/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:49:06 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:19:48 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_free_fork(t_philo *pl)
{
	unsigned int	i;

	i = 0;
	while (i < 2)
	{
		pl->forks[i]->user = 0;
		pthread_mutex_unlock(&pl->forks[i]->mt);
		pl->forks[i] = 0;
		i++;
	}
}
