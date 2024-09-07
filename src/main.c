/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 16:59:28 by erijania         ###   ########.fr       */
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
		pl_set_times(tab->philos[i++], times);
}

static int	is_arg_correct(int ac, const char **av)
{
	(void)(av);
	if (ac < 5)
		return (pl_utl_error("Error:\n > Too few argument.\n", 0));
	return (1);
}

static void	pl_extra_params(t_table *tab, int ac, const char **av)
{
	int	i;

	if (ac > 0)
	{
		i = -1;
		while (++i < ac)
			to_philo(tab->philos[i])->tt.eat = pl_utl_atoi(av[i]);
	}
}

int	main(int ac, const char **av)
{
	t_table	*tab;
	int		times[3];
	int		size;

	if (!is_arg_correct(ac, av))
		return (1);
	size = pl_utl_atoi(av[1]);
	times[0] = pl_utl_atoi(av[2]);
	times[1] = pl_utl_atoi(av[3]);
	times[2] = pl_utl_atoi(av[4]);
	tab = new_table(size);
	pl_lst_init(tab, times);
	pl_extra_params(tab, ac - 5, av + 5);
	return (philosopher(tab));
}
