/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/06 09:54:43 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

static char	*pl_state_to_string(t_pl_state state)
{
	if (state == PHILO_EATING)
		return ("is eating");
	if (state == PHILO_SLEEPING)
		return ("is sleeping");
	if (state == PHILO_THINKING)
		return ("is thinking");
	return ("has taken a fork");
}

static void	*pl_thread_exec(void *self)
{
	t_philo		*philo;
	t_pl_state	curr_state;

	philo = to_philo(self);
	curr_state = philo->state;
	printf("%ld %d %s\n", pl_utl_timestamp(), philo->rank,
		pl_state_to_string(curr_state));
	while (1)
	{
		if (curr_state != philo->state)
			printf("%ld %d %s\n", pl_utl_timestamp(), philo->rank,
				pl_state_to_string(curr_state));
		philo->tt_die--;
		philo->tt_eat--;
		usleep(1000);
	}
	return (0);
}

static void	pl_run(void *self)
{
	t_philo	*philo;

	philo = to_philo(self);
	pthread_create(&philo->pt, 0, pl_thread_exec, philo);
	philo->is_running = 1;
}

t_philo	*pl_new(int rank, int *times)
{
	t_philo	*ret;

	ret = (t_philo *)malloc(sizeof(t_philo));
	if (!ret)
		exit(1);
	ret->rank = rank;
	ret->tt_die = times[0];
	ret->tt_eat = times[1];
	ret->tt_sleep = times[2];
	ret->max_eat = 0;
	ret->state = PHILO_SLEEPING;
	ret->is_running = 0;
	ret->run = pl_run;
	return (ret);
}
