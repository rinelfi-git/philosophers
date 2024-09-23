/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_times.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:03:31 by erijania          #+#    #+#             */
/*   Updated: 2024/09/23 18:11:38 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_fork.h"

void	pl_init_times(t_table *tab, int *times)
{
	int	i;

	tab->tt.die = times[0];
	tab->tt.eat = times[1];
	tab->tt.sleep = times[2];
	i = 0;
	while (i < tab->length)
	{
		tab->philos[i]->tt.die = tab->tt.die + tab->start;
		tab->philos[i]->tt.eat = tab->tt.eat + tab->start;
		tab->philos[i]->tt.sleep = tab->tt.sleep + tab->start;
		tab->philos[i]->tt.think = tab->tt.think + tab->start;
		i++;
	}
}
