/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/08/15 17:21:30 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static void	pl_start(void *self)
{
	t_philo	*philo;

	philo = to_philo(self);
	philo->run(philo);
	philo->is_running = 1;
}

static void	pl_join(void *self)
{
	pthread_join(to_philo(self)->pt, 0);
}

int	philosopher(t_philo **philos)
{
	pl_utl_lst_foreach(philos, pl_start);
	pl_utl_lst_foreach(philos, pl_join);
	printf("Hello manarakaraka\n");
	return (0);
}
