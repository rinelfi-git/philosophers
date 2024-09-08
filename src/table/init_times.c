/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_times.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:03:31 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 12:29:58 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"

void	pl_init_times(t_table *tab, int *times)
{
	tab->tt = (t_time *)malloc(sizeof(t_time));
	if (!tab->tt)
		exit(1);
	tab->tt->die = times[0];
	tab->tt->eat = times[1];
	tab->tt->sleep = times[2];
}
