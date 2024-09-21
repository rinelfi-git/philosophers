/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/09/21 13:02:24 by erijania         ###   ########.fr       */
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
	int	i;
	int	mirror;
	
	i = 0;
	while (i <= tab->length / 2)
	{
		mirror = tab->length - 1 - i;
		tab->philos[i]->run(tab->philos[i]);
		if (mirror > i)
			tab->philos[mirror]->run(tab->philos[mirror]);
		i++;
	}
}

static void	pl_join(void *self)
{
	pthread_join(to_philo(self)->pt, 0);
}

int	philosopher(t_table *tab)
{
	pl_start(tab);
	pl_utl_lst_foreach(tab, pl_join);
	pl_free(tab);
	return (0);
}
