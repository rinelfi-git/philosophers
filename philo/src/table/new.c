/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:54:30 by erijania          #+#    #+#             */
/*   Updated: 2024/09/23 18:11:33 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pl_types.h"
#include "pl_utils.h"
#include "pl_fork.h"
#include "pl_philo.h"

static void	init_vars(t_table *tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < tab->length)
	{
		tab->forks[i] = new_fork();
		tab->philos[i] = new_philo(i, tab->forks[i]);
		tab->philos[i]->seat = tab;
		i++;
	}
	i = 0;
	while (i < tab->length)
	{
		tab->philos[i]->right = tab->forks[(i + 1) % tab->length];
		i++;
	}
}

t_table	*new_table(int length)
{
	t_table	*new;

	new = (t_table *)malloc(sizeof(t_table));
	if (!new)
		exit(1);
	pthread_mutex_init(&new->dead_lock, 0);
	new->philos = (t_philo **)malloc(sizeof(t_philo *) * length);
	new->forks = (t_fork **)malloc(sizeof(t_fork *) * length);
	new->length = length;
	new->start = pl_utl_time();
	new->max_eat = 0;
	new->tt.die = 0;
	new->tt.eat = 0;
	new->tt.sleep = 0;
	new->tt.think = TT_THINK;
	new->dead = 0;
	init_vars(new);
	return (new);
}
