/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:10:33 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 15:44:32 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_table.h"
#include "pl_philo.h"
#include "pl_fork.h"
#include <stdlib.h>

void	pl_free(void *pl)
{
	t_table	*tab;
	t_fork	*fork;
	t_philo	*philo;
	int		i;

	tab = to_philo(pl)->seat;
	i = 0;
	while (i < tab->length)
	{
		fork = tab->forks[i++];
		pthread_mutex_unlock(&fork->locker);
		pthread_mutex_destroy(&fork->locker);
		free(fork);
	}
	i = 0;
	while (i < tab->length)
	{
		philo = tab->philos[i++];
		free(philo);
	}
	free(tab->forks);
	free(tab->philos);
	free(tab);
}
