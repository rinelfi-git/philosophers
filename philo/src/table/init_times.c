/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_times.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:03:31 by erijania          #+#    #+#             */
/*   Updated: 2024/09/17 20:19:32 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"
#include "pl_fork.h"
#include <stdlib.h>

void	pl_init_times(t_table *tab, int *times)
{
	int	i;

	tab->tt = (t_time *)malloc(sizeof(t_time));
	if (!tab->tt)
		exit(1);
	tab->tt->die = times[0];
	tab->tt->eat = times[1];
	tab->tt->sleep = times[2];
	tab->tt->free = 50;
	i = 0;
	while (i < tab->length)
	{
		tab->philos[i]->tt.die = tab->tt->die + tab->start;
		tab->philos[i]->tt.eat = tab->tt->eat + tab->start;
		tab->philos[i]->tt.sleep = tab->tt->sleep + tab->start;
		tab->philos[i]->tt.free = tab->tt->free + tab->start;
		i++;
	}
}
