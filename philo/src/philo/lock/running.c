/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 17:50:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"

void	pl_set_run(t_philo *pl, int run)
{
	pthread_mutex_lock(&pl->run_lock);
	pl->is_running = run;
	pthread_mutex_unlock(&pl->run_lock);
}

int	pl_is_running(t_philo *pl)
{
	int	run;

	pthread_mutex_lock(&pl->run_lock);
	run = pl->is_running;
	pthread_mutex_unlock(&pl->run_lock);
	return (run);
}
