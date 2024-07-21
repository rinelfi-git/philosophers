/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 17:12:57 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "pl_utils.h"
#include "librj.h"
#include <stdlib.h>

static t_philo	**pl_lst_init(int size, int *times)
{
	t_philo	**pls;
	int		i;

	pls = (t_philo **)malloc(sizeof(t_philo *) * (size + 1));
	if (!pls)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		pls[i] = pl_new(i + 1, times);
		i++;
	}
	pls[i] = 0;
	return (pls);
}

int	main(int argc, t_str argv[])
{
	t_philo	**philos;
	int		times[3];
	int		size;
	int		i;

	size = pl_utl_atoi(argv[1]);
	times[0] = pl_utl_atoi(argv[2]);
	times[1] = pl_utl_atoi(argv[3]);
	times[2] = pl_utl_atoi(argv[4]);
	philos = pl_lst_init(size, times);
	i = 0;
	while (philos[i] && (i + 5) < argc)
	{
		philos[i]->max_eat = pl_utl_atoi(argv[i + 5]);
		i++;
	}
	return (philosopher(philos));
}
