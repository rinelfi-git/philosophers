/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:54:30 by erijania          #+#    #+#             */
/*   Updated: 2024/10/31 19:41:41 by erijania         ###   ########.fr       */
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

static void	init_vars(t_monitor *tab)
{
	int		i;
	t_philo	*pl;
	t_sync	*fk;

	if (!tab)
		return ;
	i = 0;
	while (i < tab->length)
	{
		fk = &tab->forks[i];
		pl = &tab->philos[i];
		pthread_mutex_init(fk, 0);
		init_philo(pl, i++, fk);
		pl->mon = tab;
	}
	i = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i];
		fk = &tab->forks[(i + 1) % tab->length];
		if (pl->left != fk)
			pl->right = fk;
		i++;
	}
}

void	init_monitor(t_monitor *tab, int length)
{
	pthread_mutex_init(&tab->self_lock, 0);
	pthread_mutex_init(&tab->dead_lock, 0);
	pthread_mutex_init(&tab->print_lock, 0);
	tab->philos = (t_philo *)malloc(sizeof(t_philo) * length);
	tab->forks = (t_sync *)malloc(sizeof(t_sync) * length);
	if (!tab->philos || !tab->forks)
		return ;
	tab->length = length;
	tab->start = pl_timestamp();
	tab->max_eat = 0;
	tab->tt.die = 0;
	tab->tt.eat = 0;
	tab->tt.sleep = 0;
	tab->tt.think = 0;
	tab->dead = 0;
	init_vars(tab);
}
