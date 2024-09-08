/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_eat_exceeded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:49:02 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 23:51:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"

int	is_max_eat_exceeded(t_philo *pl)
{
	t_table	*tab;

	tab = pl->seat;
	return (tab->max_eat && tab->max_eat < pl->max_eat);
}
