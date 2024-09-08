/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 08:40:36 by erijania         ###   ########.fr       */
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

	if (pl->seat->length < 2)
		return ;
	forks[0] = pl->seat->forks[pl->rank];
	jump = (pl->rank - 1) % pl->seat->length;
	if (jump < 0)
		jump = (jump + pl->seat->length) % pl->seat->length;
	forks[1] = pl->seat->forks[jump];
	if (forks[0]->user || forks[1]->user)
		return ;
	i = 0;
	while (i < 2)
	{
		pthread_mutex_lock(&forks[i]->locker);
		forks[i]->user = pl;
		pl->forks[i] = forks[i];
		i++;
	}
	pl->state = PHILO_EATING;
	if (pl->seat->max_eat)
		pl->max_eat++;
	printf("%ld %d has taken a fork\n", pl_utl_time(), pl->rank + 1);
}
