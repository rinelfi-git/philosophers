/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/10/26 17:39:09 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_fork.h"
#include "pl_utils.h"
#include <unistd.h>

static void take_fork(t_philo *pl, t_fork *fk)
{
	int got_it;

	got_it = 0;
	while (!got_it)
	{
		pthread_mutex_lock(&fk->use_lock);
		if (!fk->user)
		{
			fk->user = pl;
			got_it = 1;
		}
		pthread_mutex_unlock(&fk->use_lock);
		pl_usleep(pl, 0);
	}
	pl_utl_message(pl, "has taken a fork");
}

static void	take_right_first(t_philo *pl)
{
	if (pl->right)
		take_fork(pl, pl->right);
	if (pl->left)
		take_fork(pl, pl->left);
}

static void	take_left_first(t_philo *pl)
{
	if (pl->left)
		take_fork(pl, pl->left);
	if (pl->right)
		take_fork(pl, pl->right);
}

int	pl_take_fork(t_philo *pl)
{
	int out;

	out = 0;
	if (pl->rank % 2 == 0)
		take_right_first(pl);
	else
		take_left_first(pl);
	if (!pl_is_full(pl))
	{
		out = 1;
		pl->max_eat++;
		pthread_mutex_lock(&pl->state_lock);
		pl->state = PHILO_EATING;
		if (pl->tab->max_eat && pl->max_eat > pl->tab->max_eat)
		{
			pl->state = PHILO_FULL;
			out = 0;
		}
		else
			pl_utl_message(pl, "is eating");
		pthread_mutex_unlock(&pl->state_lock);
	}
	return (out);
}
