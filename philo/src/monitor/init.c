/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:54:30 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 14:43:09 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pl_types.h"
#include "pl_utils.h"
#include "pl_philo.h"

static void	init_vars(t_monitor *mon)
{
	int		i;
	t_philo	*pl;
	t_sync	*fk;

	if (!mon)
		return ;
	i = 0;
	while (i < mon->size)
	{
		fk = &mon->fork_list[i];
		pl = &mon->philosopher_list[i];
		pthread_mutex_init(fk, 0);
		init_philo(pl, i++, fk);
		pl->monitor = mon;
	}
	i = 0;
	while (i < mon->size)
	{
		pl = &mon->philosopher_list[i];
		fk = &mon->fork_list[(i + 1) % mon->size];
		if (pl->left_fork != fk)
			pl->right_fork = fk;
		i++;
	}
}

void	init_monitor(t_monitor *mon, int length)
{
	pthread_mutex_init(&mon->dead_lock, 0);
	pthread_mutex_init(&mon->print_lock, 0);
	mon->philosopher_list = (t_philo *)malloc(sizeof(t_philo) * length);
	mon->fork_list = (t_sync *)malloc(sizeof(t_sync) * length);
	if (!mon->philosopher_list || !mon->fork_list)
		return ;
	mon->size = length;
	mon->start_time = pl_timestamp();
	mon->eat_limit = 0;
	mon->time_to.die = 0;
	mon->time_to.eat = 0;
	mon->time_to.sleep = 0;
	mon->dead = 0;
	init_vars(mon);
}
