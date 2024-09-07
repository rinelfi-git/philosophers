/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 15:39:10 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_fork.h"
#include "pl_utils.h"

void	pl_take_fork(t_philo *pl)
{
	t_fork	*forks[2];
	int		i;
	int		jump;

	forks[0] = pl->seat->forks[pl->rank];
	jump = (pl->rank - 1) % pl->seat->length;
	if (jump < 0)
		jump = (jump + pl->seat->length) % pl->seat->length;
	forks[1] = pl->seat->forks[jump];
	i = 0;
	if (forks[0]->user || forks[1]->user)
		return ;
	while (i < 2)
	{
		pthread_mutex_lock(&forks[i]->locker);
		forks[i]->user = pl;
		pl->forks[i] = forks[i];
		i++;
	}
	pl->state = PHILO_EATING;
	printf("%ld %d has taken a fork\n", pl_utl_time(), pl->rank);
}
