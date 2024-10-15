/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/10/15 11:56:10 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

static void	eating(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pl->tt.sleep = tab->tt.sleep + time;
	pl->tt.think = TT_THINK + time;
	if (pl->tt.eat <= time)
		pl_free_fork(pl);
}

static void	sleeping(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pl->tt.eat = tab->tt.eat + time;
	pl->tt.think = TT_THINK + time;
	if (pl->tt.sleep <= time)
		pl_set_state(pl, PHILO_THINKING);
}

static void	waiting(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pl->tt.sleep = tab->tt.sleep + time;
	pl->tt.eat = tab->tt.eat + time;
	pl->tt.think = tab->tt.think + time;
}

static void	thinking(t_philo *pl, long time)
{
	t_table	*tab;

	tab = pl->tab;
	pl->tt.sleep = tab->tt.sleep + time;
	pl->tt.eat = tab->tt.eat + time;
	pl_set_state(pl, PHILO_THINKING);
}

void	pl_check_state(t_philo *pl, long time)
{
	t_state	state;

	state = pl_get_state(pl);
	if (state == PHILO_NONE)
		waiting(pl, time);
	if (state == PHILO_EATING)
		eating(pl, time);
	if (state == PHILO_SLEEPING)
		sleeping(pl, time);
	if (state == PHILO_THINKING)
		thinking(pl, time);
	if (pl->tt.die + ROOM <= time)
		pl_set_state(pl, PHILO_DEAD);
}
