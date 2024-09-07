/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:54:30 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 13:49:19 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pl_table.h"
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
		tab->philos[i] = new_philo(i);
		to_philo(tab->philos[i])->seat = tab;
		i++;
	}
}

t_table	*new_table(int length)
{
	t_table	*new;

	new = (t_table *)malloc(sizeof(t_table));
	if (!new)
		exit(1);
	new->forks = malloc(sizeof(t_philo *) * length);
	new->philos = malloc(sizeof(t_fork *) * length);
	new->length = length;
	init_vars(new);
	return (new);
}
