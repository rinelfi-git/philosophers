/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 15:58:21 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "pl_utils.h"
#include <stdlib.h>

static t_philo	**pl_lst_init(int size)
{
	t_philo	**pls;
	int		i;

	pls = (t_philo **)malloc(sizeof(t_philo *) * (size + 1));
	if (!pls)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		pls[i] = pl_new(i + 1);
		i++;
	}
	pls[i] = 0;
	return (pls);
}



int	main(int argc, char **argv)
{
	t_philo	**philos;
	int		size;
	int		i;

	(void)(argc);
	printf("INIT\n");
	size = pl_atoi(argv[1]);
	printf("INIT %d\n", size);
	philos = pl_lst_init(size);
	i = 0;
	while (philos[i])
	{
		printf("Rank is %d.\n", philos[i]->rank);
		i++;
	}
	return (0);
}
