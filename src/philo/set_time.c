/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:49:27 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 10:51:43 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_set_times(t_philo *pl, int tt_die, int tt_eat, int tt_sleep)
{
	pl->tt_die = tt_die;
	pl->tt_eat = tt_eat;
	pl->tt_sleep = tt_sleep;
}
