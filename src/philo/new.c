/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 15:29:58 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"
#include "pl_fork.h"
#include <stdlib.h>
#include <unistd.h>

static void	pl_run(void *self)
{
	t_philo	*philo;

	philo = to_philo(self);
	pthread_create(&philo->pt, 0, pl_exec, philo);
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
	ret->state = PHILO_THINKING;
	ret->seat = 0;
	ret->run = pl_run;
	return (ret);
}
