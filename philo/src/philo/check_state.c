/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:23:48 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 18:27:32 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

int	pl_eating(t_philo *pl)
{
	t_table	*tab;
	int		out;

	tab = pl->tab;
	pl->tt.die = tab->tt.die + pl_utl_timestamp();
	out = 1;
	pl->max_eat++;
	pl_utl_message(pl, "is eating");
	if (!pl_usleep(pl, tab->tt.eat))
		out = 0;
	pl_free_fork(pl);
	return (out);
}

int	pl_sleeping(t_philo *pl)
{
	t_table	*tab;
	int		out;

	tab = pl->tab;
	out = 1;
	pl_utl_message(pl, "is sleeping");
	if (!pl_usleep(pl, tab->tt.sleep))
		out = 0;
	return (out);
}

int	pl_thinking(t_philo *pl)
{
	int		out;

	out = 1;
	pl_utl_message(pl, "is thinking");
	if (!pl_usleep(pl, 0))
		out = 0;
	return (out);
}
