/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/11/07 15:20:15 by erijania         ###   ########.fr       */
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
		return (print_error("Error:\n > Format should be "
				"(./philo size tt_die tt_eat tt_sleep [eat_limit]).\n", 0));
	i = 1;
	while (i < ac)
		if (!ft_isnumber(av[i++]))
			return (print_error("Error:\n > Arguments must be numbers.\n", 0));
	i = 1;
	while (i < ac)
		if (!ft_isinteger(av[i++]))
			return (print_error("Error:\n"
					"> Integer values only [-2147483648, 2147483647].\n", 0));
	i = 1;
	while (i < ac)
		if (ft_atoi(av[i++]) <= 0)
			return (print_error(
					"Error:\n > Numbers must be greater than zero.\n", 0));
	if (ft_atoi(av[1]) > 200)
		return (print_error("Warning:\n > "
				"It's too much of philosophers.\n", 0));
	return (1);
}

void	init_times(t_monitor *monitor, int *times)
{
	monitor->time_to.die = times[0];
	monitor->time_to.eat = times[1];
	monitor->time_to.sleep = times[2];
}

int	main(int ac, char **av)
{
	t_monitor	monitor;
	int			times[3];
	int			size;

	if (!is_arg_correct(ac, av))
		return (1);
	size = ft_atoi(av[1]);
	times[0] = ft_atoi(av[2]);
	times[1] = ft_atoi(av[3]);
	times[2] = ft_atoi(av[4]);
	monitor_init(&monitor, size);
	init_times(&monitor, times);
	if (ac == 6)
		monitor.eat_limit = ft_atoi(av[5]);
	return (execution(&monitor));
}
