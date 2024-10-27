/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:06:03 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 23:10:57 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"

void	pl_end(t_monitor *tab)
{
	int		i;
	t_philo	*pl;

	i = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i++];
		pl->stop(pl);
	}
}

static void	mutex_fork_destroy(t_fork *fk)
{
	pthread_mutex_destroy(&fk->use_lock);
}

static void	mutex_philo_destroy(t_philo *pl)
{
	pthread_mutex_destroy(&pl->self_lock);
	pthread_mutex_destroy(&pl->time_lock);
	pthread_mutex_destroy(&pl->state_lock);
	pthread_mutex_destroy(&pl->run_lock);
}

static void	mutex_table_destroy(t_monitor *tab)
{
	pthread_mutex_destroy(&tab->self_lock);
	pthread_mutex_destroy(&tab->dead_lock);
}

void	pl_free(t_monitor *tab)
{
	int		i;
	t_fork	*fk;
	t_philo	*pl;

	i = 0;
	while (i < tab->length)
	{
		pl = &tab->philos[i];
		fk = &tab->forks[i++];
		mutex_fork_destroy(fk);
		mutex_philo_destroy(pl);
	}
	mutex_table_destroy(tab);
	free(tab->forks);
	free(tab->philos);
}
