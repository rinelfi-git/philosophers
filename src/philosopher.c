/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 20:50:14 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_utils.h"
#include <stdlib.h>

static void	print_philo(t_philo *philo)
{
	printf("PHILO %d, TIMES[%d, %d, %d] MAX %d\n", philo->rank,
		philo->tt_die, philo->tt_eat, philo->tt_sleep, philo->max_eat);
}

int	philosopher(t_philo **lst)
{
	pl_utl_lst_foreach(lst, print_philo);
	pl_utl_lst_foreach(lst, free);
	return (0);
}
