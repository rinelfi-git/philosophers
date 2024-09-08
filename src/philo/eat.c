/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:51:53 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 09:58:18 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

void	pl_eat(t_philo *pl, t_times *tt)
{
	tt->die = pl->tt.die;
	tt->sleep = pl->tt.sleep;
	tt->eat--;
}
