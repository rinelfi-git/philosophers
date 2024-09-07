/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:51:53 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:07:17 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_eat(t_philo *pl, t_times *tt)
{
	pl->state = PHILO_EATING;
	tt->eat--;
	tt->die = pl->tt.die;
	tt->sleep = pl->tt.sleep;
}
