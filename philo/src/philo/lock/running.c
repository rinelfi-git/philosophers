/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/10/15 11:56:27 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"

void	pl_set_run(t_philo *pl, int run)
{
	pthread_mutex_lock(&pl->self_lock);
	pl->is_running = run;
	pthread_mutex_unlock(&pl->self_lock);
}

int	pl_is_running(t_philo *pl)
{
	int	run;

	pthread_mutex_lock(&pl->self_lock);
	run = pl->is_running;
	pthread_mutex_unlock(&pl->self_lock);
	return (run);
}
