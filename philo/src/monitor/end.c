/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:06:03 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 17:32:38 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

void	pl_end(t_monitor *mon)
{
	int		i;
	t_philo	*pl;

	i = 0;
	while (i < mon->length)
	{
		pl = &mon->philos[i++];
		pl_set_run(pl, 0);
	}
}

static void	mutex_table_destroy(t_monitor *tab)
{
	pthread_mutex_destroy(&tab->dead_lock);
}

void	pl_free(t_monitor *tab)
{
	int		i;
	t_sync	*fk;

	i = 0;
	while (i < tab->length)
	{
		fk = &tab->forks[i++];
		pthread_mutex_destroy(fk);
	}
	mutex_table_destroy(tab);
	free(tab->forks);
	free(tab->philos);
}
