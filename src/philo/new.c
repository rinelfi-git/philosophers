/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:55:00 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"
#include "pl_fork.h"
#include <stdlib.h>
#include <unistd.h>

static char	*pl_str_state(t_pl_state state)
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
	t_philo		*pl;
	t_pl_state	curr_state;
	t_times		tt;

	pl = to_philo(self);
	curr_state = pl->state;
	tt = pl->tt;
	printf("%ld %d %s\n", pl_utl_time(), pl->rank, pl_str_state(curr_state));
	while (pl->tt.die)
	{
		if (curr_state != pl->state)
			printf("%ld %d %s\n", pl_utl_time(), pl->rank,
				pl_str_state(curr_state));
		if (!tt.sleep)
			pl_think(pl, &tt);
		if (curr_state == PHILO_THINKING)
		{
			pl_take_fork(pl);
			pl_eat(pl, &tt);
		}
		usleep(1000);
	}
	printf("%ld %d is dead\n", pl_utl_time(), pl->rank);
	return (0);
}

static void	pl_run(void *self)
{
	t_philo	*philo;

	philo = to_philo(self);
	pthread_create(&philo->pt, 0, pl_thread_exec, philo);
}

t_philo	*new_philo(int rank)
{
	t_philo	*ret;

	ret = (t_philo *)malloc(sizeof(t_philo));
	if (!ret)
		exit(1);
	ret->rank = rank;
	ret->tt.die = 0;
	ret->tt.eat = 0;
	ret->tt.sleep = 0;
	ret->forks[0] = 0;
	ret->forks[1] = 0;
	ret->max_eat = 0;
	ret->state = PHILO_SLEEPING;
	ret->is_running = 0;
	ret->seat = 0;
	ret->run = pl_run;
	return (ret);
}
