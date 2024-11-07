/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:30:55 by erijania          #+#    #+#             */
/*   Updated: 2024/11/07 15:19:34 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

void	philosopher_set_run(t_philo *philo, int run)
{
	pthread_mutex_lock(&philo->run_lock);
	philo->is_running = run;
	pthread_mutex_unlock(&philo->run_lock);
}

int	philosopher_get_run(t_philo *philo)
{
	int	run;

	pthread_mutex_lock(&philo->run_lock);
	run = philo->is_running;
	pthread_mutex_unlock(&philo->run_lock);
	return (run && get_philo_state(philo) != PHILO_DEAD);
}
