/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:10:33 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 16:18:56 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_table.h"
#include "pl_philo.h"
#include "pl_fork.h"
#include <stdlib.h>

void	pl_free(void *tab)
{
	t_fork	*fork;
	int		i;

	tab = to_table(tab);
	i = 0;
	while (i < to_table(tab)->length)
	{
		fork = to_table(tab)->forks[i++];
		pthread_mutex_unlock(&fork->locker);
		pthread_mutex_destroy(&fork->locker);
		free(fork);
	}
	i = 0;
	while (i < to_table(tab)->length)
		free(to_table(tab)->philos[i++]);
	free(to_table(tab)->forks);
	free(to_table(tab)->philos);
	free(tab);
}
