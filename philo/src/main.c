/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 14:54:05 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_monitor.h"
#include "pl_utils.h"
#include <stdlib.h>

static int	is_arg_correct(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (pl_error("Error:\n > Format should be "
				"(./philo size tt_die tt_eat tt_sleep [eat_limit]).\n", 0));
	i = 1;
	while (i < ac)
		if (!pl_isnumber(av[i++]))
			return (pl_error("Error:\n > Arguments must be numbers.\n", 0));
	i = 1;
	while (i < ac)
		if (!pl_isinteger(av[i++]))
			return (pl_error("Error:\n"
					"> Integer values only [-2147483648, 2147483647].\n", 0));
	i = 1;
	while (i < ac)
		if (pl_atoi(av[i++]) <= 0)
			return (pl_error(
					"Error:\n > Numbers must be greater than zero.\n", 0));
	if (pl_atoi(av[1]) > 200)
		return (pl_error("Warning:\n > "
				"It's too much of philosophers.\n", 0));
	return (1);
}

void	init_times(t_monitor *tab, int *times)
{
	tab->time_to.die = times[0];
	tab->time_to.eat = times[1];
	tab->time_to.sleep = times[2];
}

int	main(int ac, char **av)
{
	t_monitor	monitor;
	int			times[3];
	int			size;

	if (!is_arg_correct(ac, av))
		return (1);
	size = pl_atoi(av[1]);
	times[0] = pl_atoi(av[2]);
	times[1] = pl_atoi(av[3]);
	times[2] = pl_atoi(av[4]);
	init_monitor(&monitor, size);
	init_times(&monitor, times);
	if (ac == 6)
		monitor.eat_limit = pl_atoi(av[5]);
	return (philosopher(&monitor));
}
