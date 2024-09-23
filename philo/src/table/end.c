/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:06:03 by erijania          #+#    #+#             */
/*   Updated: 2024/09/23 18:29:00 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

void	pl_end(t_table *tab)
{
	int		i;
	t_philo	*pl;

	i = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i++];
		pl->is_running = !tab->dead && !is_max_eat_exceeded(pl);
		if (is_max_eat_exceeded(pl))
			pl_free_fork(pl);
	}
}
