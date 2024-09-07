/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:54:30 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 10:55:45 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_table.h"
#include <stdlib.h>

static void	init_forks(t_fork **obj, const unsigned int length)
{
	unsigned int	i;

	i = 0;
	while (i < length)
		obj[i++] = new_fork();
}

static void	init_philos(t_philo **obj, const unsigned int length)
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
	init_forks(new->forks, length);
	init_philos(new->philos, length);
	new->length = length;
}
