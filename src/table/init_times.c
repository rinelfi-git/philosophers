/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_times.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:03:31 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:54:24 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_table.h"
#include "pl_philo.h"

void	pl_init_times(t_table *tab, int *times)
{
	int	i;

	i = 0;
	while (i < tab->length)
		pl_set_times(tab->philos[i++], times);
}
