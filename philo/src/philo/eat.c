/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:51:53 by erijania          #+#    #+#             */
/*   Updated: 2024/09/23 18:50:05 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

void	pl_eat(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pl->tt.sleep = tab->tt.sleep + time;
}
