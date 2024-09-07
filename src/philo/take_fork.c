/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 10:30:10 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_take_fork(t_philo *pl, t_table *tab)
{
	t_fork	*forks[2];
	int		i;

	forks[0] = tab->forks[pl->rank];
	forks[1] = tab->forks[(pl->rank - 1) % tab->length];
	i = 0;
	while (i < 2)
	{
		pthread_mutex_lock(&forks[i]->mt);
		forks[i]->user = pl;
		pl->forks[i] = forks[i];
		i++;
	}
}
