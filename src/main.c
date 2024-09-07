/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 10:56:57 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_table.h"
#include "pl_utils.h"
#include <stdlib.h>

static void	pl_lst_init(t_table *tab, int *times)
{
	int		i;

	i = 0;
	while (i < tab->length)
		pl_set_times(tab->philos[i++], times[0], times[1], times[2]);
}

static int	is_arg_correct(int argc, const char **argv)
{
	(void)(argv);
	if (argc < 5)
		return (pl_utl_error("Error:\n > Too few argument.\n", 0));
	return (1);
}

int	main(int argc, const char **argv)
{
	t_table	*tab;
	t_philo	**philos;
	int		times[3];
	int		size;
	int		i;

	if (!is_arg_correct(argc, argv))
		return (1);
	size = pl_utl_atoi(argv[1]);
	times[0] = pl_utl_atoi(argv[2]);
	times[1] = pl_utl_atoi(argv[3]);
	times[2] = pl_utl_atoi(argv[4]);
	tab = new_tab(size);
	pl_lst_init(size, times);
	i = 0;
	while (philos[i] && (i + 5) < argc)
	{
		philos[i]->max_eat = pl_utl_atoi(argv[i + 5]);
		i++;
	}
	return (philosopher(philos));
}
