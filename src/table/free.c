/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:10:33 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 15:23:42 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_table.h"
#include "pl_philo.h"
#include <stdlib.h>

void	pl_free(void *pl)
{
	t_table	*tab;
	int		i;

	tab = to_philo(pl)->seat;
	i = 0;
	while (i < tab->length)
		free(tab->forks[i++]);
	i = 0;
	while (i < tab->length)
		free(tab->philos[i++]);
	free(tab->forks);
	free(tab->philos);
	free(tab);
}
