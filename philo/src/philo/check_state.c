/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/10/26 18:06:42 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

int	pl_eating(t_philo *pl)
{
	t_table *tab;
	int out;

	tab = pl->tab;
	pl->tt.die = tab->tt.die + pl_utl_timestamp();
	out = 1;
	if (!pl_usleep(pl, tab->tt.eat))
		out = 0;
	pl_free_fork(pl);
	if (out)
	{
		pl_set_state(pl, PHILO_SLEEPING);
		pl_utl_message(pl, "is sleeping");
	}
	return (out);
}

int	pl_sleeping(t_philo *pl)
{
	t_table *tab;
	int out;

	tab = pl->tab;
	out = 1;
	if (!pl_usleep(pl, tab->tt.sleep))
		out = 0;
	if (out)
	{
		pl_set_state(pl, PHILO_THINKING);
		pl_utl_message(pl, "is thinking");
	}
	return (out);
}
