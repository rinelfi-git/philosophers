/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:49:38 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_fork.h"

void	pl_take_fork(t_philo *pl)
{
	t_fork	*forks[2];
	int		i;

	forks[0] = pl->seat->forks[pl->rank];
	forks[1] = pl->seat->forks[(pl->rank - 1) % pl->seat->length];
	i = 0;
	while (i < 2)
	{
		pthread_mutex_lock(&forks[i]->mt);
		forks[i]->user = pl;
		pl->forks[i] = forks[i];
		i++;
	}
}
