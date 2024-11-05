/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:38:08 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 15:10:09 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	list_foreach(t_monitor *tab, void (*call)())
{
	int	i;

	i = 0;
	while (i < tab->size)
	{
		call(tab->philosopher_list + i, i);
		i++;
	}
}
