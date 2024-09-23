/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:10:33 by erijania          #+#    #+#             */
/*   Updated: 2024/09/23 18:38:08 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include <stdlib.h>

void	pl_free(t_table *tab)
{
	int		i;
	t_fork	*fk;

	i = 0;
	while (i < tab->length)
	{
		fk = &tab->forks[i++];
		pthread_mutex_unlock(&fk->lock);
		pthread_mutex_destroy(&fk->lock);
	}
	free(tab->forks);
	free(tab->philos);
}
