/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:10:33 by erijania          #+#    #+#             */
/*   Updated: 2024/09/09 00:11:50 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"
#include <stdlib.h>

void	pl_free(t_table *tab)
{
	int		i;

	i = 0;
	while (i < tab->length)
	{
		pthread_mutex_unlock(&tab->forks[i]->lock);
		pthread_mutex_destroy(&tab->forks[i]->lock);
		free(tab->forks[i]);
		i++;
	}
	i = 0;
	while (i < tab->length)
		free(tab->philos[i++]);
	free(tab->forks);
	free(tab->philos);
	free(tab->tt);
	free(tab);
}
