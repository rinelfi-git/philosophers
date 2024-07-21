/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 17:47:01 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "librj.h"
#include <stdlib.h>

static void	ft_run(void *self)
{
	printf("PHILO %d is ON\n", to_philo(self)->rank);
}

void	pl_destroy(void	*self)
{
	free(self);
}

t_philo	*pl_new(int rank, int *times)
{
	t_philo	*ret;

	ret = (t_philo *)malloc(sizeof(t_philo));
	if (!ret)
		exit(1);
	ret->rank = rank;
	ret->fork = 1;
	ret->tt_die = times[0];
	ret->tt_eat = times[1];
	ret->tt_sleep = times[2];
	ret->max_eat = 0;
	ret->state = PHILO_SLEEPING;
	ret->run = ft_run;
	to_obj(ret)->destroy = pl_destroy;
	return (ret);
}
