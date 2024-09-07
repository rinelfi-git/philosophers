/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:54:30 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:12:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_table.h"
#include <stdlib.h>

static void	init_vars(t_table *tab)
{
	unsigned int	i;

	i = 0;
	while (i < tab->length)
	{
		tab->forks[i] = new_fork();
		tab->philos[i] = new_philo(i);
		tab->philos[i]->seat = tab;
		i++;
	}
}

static void	init_philos(t_table *tab, t_philo **obj, const unsigned int length)
{
	unsigned int	i;

	i = 0;
	while (i < length)
		obj[i++] = new_philo(i);
}

t_table	*new_table(int length)
{
	t_table	*new;

	new = (t_table *)malloc(sizeof(t_table));
	if (!new)
		exit(1);
	new->forks = (t_fork **)malloc(sizeof(t_philo *) * length);
	new->philos = (t_philo **)malloc(sizeof(t_fork *) * length);
	init_vars(new);
	new->length = length;
}
