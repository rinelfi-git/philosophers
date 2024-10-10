/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:06:03 by erijania          #+#    #+#             */
/*   Updated: 2024/10/10 18:33:04 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

void	pl_end(t_table *tab)
{
	int		i;
	t_philo	*pl;
	long	time;

	i = 0;
	time = pl_utl_timestamp();
	while (i < tab->length)
	{
		pl = &tab->philos[i++];
		pl->stop(pl, time);
	}
}
