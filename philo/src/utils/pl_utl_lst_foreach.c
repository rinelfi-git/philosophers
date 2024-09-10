/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utl_lst_foreach.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:38:08 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:56:11 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_utl_lst_foreach(t_table *tab, void (*call)())
{
	int	i;

	i = 0;
	while (i < tab->length)
	{
		call(tab->philos[i], i);
		i++;
	}
}
