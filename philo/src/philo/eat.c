/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:51:53 by erijania          #+#    #+#             */
/*   Updated: 2024/09/17 22:45:41 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"
#include "pl_utils.h"

void	pl_eat(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->seat;
	pl->tt.sleep = tab->tt->sleep + time;
}
