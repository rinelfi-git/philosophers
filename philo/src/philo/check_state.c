/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/10/09 19:48:33 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

static void	eating(t_philo *pl, long time)
{
	t_table	*tab;
	t_time	*tt;

	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	tt = &pl->tt;
	pthread_mutex_unlock(&pl->time_lock);
	tt->sleep = tab->tt.sleep + time;
	tt->think = TT_THINK + time;
	if (tt->eat <= time)
		pl_free_fork(pl);
}

static void	sleeping(t_philo *pl, long time)
{
	t_table	*tab;
	t_time	*tt;

	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	tt = &pl->tt;
	pthread_mutex_unlock(&pl->time_lock);
	tt->eat = tab->tt.eat + time;
	tt->think = TT_THINK + time;
	if (tt->sleep <= time)
		pl_set_state(pl, PHILO_THINKING);
}

static void	waiting(t_philo *pl, long time)
{
	t_table	*tab;
	t_time	*tt;

	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	tt = &pl->tt;
	pthread_mutex_unlock(&pl->time_lock);
	tt->sleep = tab->tt.sleep + time;
	tt->eat = tab->tt.eat + time;
	tt->think = tab->tt.think + time;
}

static void	thinking(t_philo *pl, long time)
{
	t_table	*tab;
	t_time	*tt;

	tab = pl->tab;
	pthread_mutex_lock(&pl->time_lock);
	tt = &pl->tt;
	pthread_mutex_unlock(&pl->time_lock);
	tt->sleep = tab->tt.sleep + time;
	tt->eat = tab->tt.eat + time;
	pl_set_state(pl, PHILO_THINKING);
}

void	pl_check_state(t_philo *pl, long time)
{
	t_state	state;
	
	pthread_mutex_lock(&pl->state_lock);
	state = pl->state;
	pthread_mutex_unlock(&pl->state_lock);
	if (state == PHILO_NONE)
		waiting(pl, time);
	if (state == PHILO_EATING)
		eating(pl, time);
	if (state == PHILO_SLEEPING)
		sleeping(pl, time);
	if (state == PHILO_THINKING)
		thinking(pl, time);
}
