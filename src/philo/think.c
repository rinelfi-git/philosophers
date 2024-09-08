/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:58:29 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 13:05:28 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_think(t_philo *pl, long curr_time)
{
	t_table	*tab;

	tab = pl->seat;
	pl->state = PHILO_THINKING;
	pl->tt.sleep = tab->tt->sleep + curr_time;
	pl->tt.eat = tab->tt->eat + curr_time;
}
