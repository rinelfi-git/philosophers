/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:06:03 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 23:47:01 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"
#include "pl_utils.h"

void	pl_stop(t_table *tab)
{
	int		i;
	t_philo	*pl;

	i = 0;
	while (i < tab->length)
	{
		pl = tab->philos[i++];
		pl->is_running = !tab->dead
			&& (!tab->max_eat || pl->max_eat <= tab->max_eat);
		if (tab->max_eat && pl->max_eat > tab->max_eat)
			pl_free_fork(pl);
	}
}
