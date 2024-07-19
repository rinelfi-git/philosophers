/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/07/19 14:24:44 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

static void	ft_run(void *phylo)
{
	printf("PHILO %d is ON\n", to_philo(phylo)->rank);
}

t_philo	*n_philo(int rank)
{
	t_philo	*ft;

	ft = (t_philo *)malloc(sizeof(t_philo));
	if (!ft)
		exit(1);
	ft->rank = rank;
	ft->state = PHILO_SLEEPING;
	ft->run = ft_run;
	return (ft);
}
