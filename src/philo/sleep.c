/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:58:29 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:07:45 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_sleep(t_philo *pl, t_times *tt)
{
	pl->state = PHILO_SLEEPING;
	tt->sleep--;
	tt->die--;
	tt->eat = pl->tt.eat;
}
