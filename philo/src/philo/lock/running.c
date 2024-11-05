/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 15:07:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

void	philosopher_set_run(t_philo *pl, int run)
{
	pthread_mutex_lock(&pl->run_lock);
	pl->is_running = run;
	pthread_mutex_unlock(&pl->run_lock);
}

int	philosopher_get_run(t_philo *pl)
{
	int	run;

	pthread_mutex_lock(&pl->run_lock);
	run = pl->is_running;
	pthread_mutex_unlock(&pl->run_lock);
	return (run && get_philo_state(pl) != PHILO_DEAD);
}
