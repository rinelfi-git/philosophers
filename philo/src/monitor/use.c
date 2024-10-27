/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_times.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:03:31 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 23:07:10 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_fork.h"

void	pl_init_times(t_monitor *tab, int *times)
{
	int		i;
	t_philo	*pl;

	tab->tt.die = times[0];
	tab->tt.eat = times[1];
	tab->tt.sleep = times[2];
	i = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i++];
		pl->tt.die = tab->tt.die + tab->start;
		pl->tt.eat = tab->tt.eat;
		pl->tt.sleep = tab->tt.sleep;
	}
}
