/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 16:16:40 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static void	ft_run(void *phylo)
{
	printf("PHILO %d is ON\n", to_philo(phylo)->rank);
}

t_philo	*pl_new(int rank, int *times, int eat_times)
{
	t_philo	*ft;

	ft = (t_philo *)malloc(sizeof(t_philo));
	if (!ft)
		exit(1);
	ft->rank = rank;
	ft->fork = 1;
	ft->tt_die = times[0];
	ft->tt_eat = times[1];
	ft->tt_sleep = times[2];
	ft->state = PHILO_SLEEPING;
	ft->run = ft_run;
	return (ft);
}
