/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/09/23 19:53:20 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_table.h"
#include "pl_philo.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static void	pl_start(t_table *tab)
{
	int		indexes[2];
	t_philo	*pl;

	indexes[0] = 0;
	while (indexes[0] <= tab->length / 2)
	{
		indexes[1] = tab->length - 1 - indexes[0];
		pl = &tab->philos[indexes[0]];
		pl->run(pl);
		if (indexes[1] > indexes[0])
		{
			pl = &tab->philos[indexes[1]];
			pl->run(pl);
		}
		indexes[0]++;
	}
}

static void	pl_join(void *self)
{
	t_philo	*pl;

	pl = to_philo(self);
	pthread_join(pl->thread, 0);
}

int	philosopher(t_table *tab)
{
	pl_start(tab);
	pl_utl_lst_foreach(tab, pl_join);
	pl_free(tab);
	return (0);
}
