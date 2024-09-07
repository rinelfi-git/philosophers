/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:06:03 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 22:15:26 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_table.h"
#include "pl_philo.h"

void	pl_stop(t_table *tab)
{
	int		i;
	int		has_dead;
	t_philo	*pl;

	i = 0;
	has_dead = 0;
	while (!has_dead && i < tab->length)
	{
		pl = to_philo(tab->philos[i++]);
		has_dead = pl->state == PHILO_DEAD;
	}
	i = 0;
	while (i < tab->length)
	{
		pl = to_philo(tab->philos[i++]);
		pl->is_running = !has_dead && pl->max_eat < tab->max_eat;
	}
}
