/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:06:03 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 19:39:28 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

void	pl_end(t_table *tab)
{
	int		i;
	int		everyone_is_alive;
	int		exceeded;
	t_philo	*pl;

	i = 0;
	pthread_mutex_lock(&tab->dead_lock);
	everyone_is_alive = !tab->dead;
	pthread_mutex_unlock(&tab->dead_lock);
	while (i < tab->length)
	{
		pl = &tab->philos[i++];
		exceeded = is_max_eat_exceeded(pl);
		if (exceeded)
			pl_free_fork(pl);
		if (!everyone_is_alive)
			pl->stop(pl);
	}
}
