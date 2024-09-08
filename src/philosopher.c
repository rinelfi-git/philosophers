/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 13:51:21 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"
#include "pl_table.h"
#include "pl_philo.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static void	pl_start(void *self)
{
	t_philo	*philo;

	philo = to_philo(self);
	philo->run(philo);
}

static void	pl_join(void *self)
{
	pthread_join(to_philo(self)->pt, 0);
}

int	philosopher(t_table *tab)
{
	pl_utl_lst_foreach(tab, pl_start);
	pl_utl_lst_foreach(tab, pl_join);
	pl_free(tab);
	return (0);
}
