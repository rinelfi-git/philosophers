/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/10/09 17:39:46 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

static void	eating(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	pl->tt.sleep = tab->tt.sleep + time;
	pl->tt.think = TT_THINK + time;
	pthread_mutex_unlock(&pl->time_lock);
	if (pl->tt.eat <= time)
		pl_free_fork(pl);
}

static void	sleeping(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	pl->tt.eat = tab->tt.eat + time;
	pl->tt.think = TT_THINK + time;
	pthread_mutex_unlock(&pl->time_lock);
	if (pl->tt.sleep <= time)
		pl->state = PHILO_THINKING;
}

static void	waiting(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	pl->tt.sleep = tab->tt.sleep + time;
	pl->tt.eat = tab->tt.eat + time;
	pl->tt.think = tab->tt.think + time;
	pthread_mutex_unlock(&pl->time_lock);
}

static void	thinking(t_philo *pl, long time)
{
	t_table	*tab;

	pl->state = PHILO_THINKING;
	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	pl->tt.sleep = tab->tt.sleep + time;
	pl->tt.eat = tab->tt.eat + time;
	pthread_mutex_unlock(&pl->time_lock);
}

void	pl_check_state(t_philo *pl, long time)
{
	if (pl->state == PHILO_NONE)
		waiting(pl, time);
	if (pl->state == PHILO_EATING)
		eating(pl, time);
	if (pl->state == PHILO_SLEEPING)
		sleeping(pl, time);
	if (pl->state == PHILO_THINKING)
		thinking(pl, time);
}
