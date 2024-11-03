/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:54:30 by erijania          #+#    #+#             */
/*   Updated: 2024/11/03 21:40:04 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pl_types.h"
#include "pl_utils.h"
#include "pl_philo.h"

t_monitor	*to_monitor(void *obj)
{
	return ((t_monitor *) obj);
}

static void	init_vars(t_monitor *mon)
{
	int		i;
	t_philo	*pl;
	t_sync	*fk;

	if (!mon)
		return ;
	i = 0;
	while (i < mon->length)
	{
		fk = &mon->forks[i];
		pl = &mon->philos[i];
		pthread_mutex_init(fk, 0);
		init_philo(pl, i++, fk);
		pl->mon = mon;
	}
	i = 0;
	while (i < mon->length)
	{
		pl = &mon->philos[i];
		fk = &mon->forks[(i + 1) % mon->length];
		if (pl->left != fk)
			pl->right = fk;
		i++;
	}
}

void	init_monitor(t_monitor *mon, int length)
{
	pthread_mutex_init(&mon->dead_lock, 0);
	pthread_mutex_init(&mon->print_lock, 0);
	mon->philos = (t_philo *)malloc(sizeof(t_philo) * length);
	mon->forks = (t_sync *)malloc(sizeof(t_sync) * length);
	if (!mon->philos || !mon->forks)
		return ;
	mon->length = length;
	mon->start = pl_timestamp();
	mon->max_eat = 0;
	mon->tt.die = 0;
	mon->tt.eat = 0;
	mon->tt.sleep = 0;
	mon->tt.think = 0;
	mon->dead = 0;
	init_vars(mon);
}
