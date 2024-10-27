/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 18:25:57 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_fork.h"
#include "pl_philo.h"
#include "pl_utils.h"
#include <unistd.h>

static int	take_fork(t_philo *pl, t_fork *fk)
{
	int	out;

	out = 0;
	pthread_mutex_lock(&fk->use_lock);
	if (!fk->user)
	{
		fk->user = pl;
		out = 1;
		pl_utl_message(pl, "has taken a fork");
	}
	else if (fk->user == pl)
		out = 1;
	pthread_mutex_unlock(&fk->use_lock);
	return (out);
}

static int	take_right_first(t_philo *pl)
{
	int	total;

	total = 0;
	if (pl->right)
		total += take_fork(pl, pl->right);
	if (pl->left)
		total += take_fork(pl, pl->left);
	return (total);
}

static int	take_left_first(t_philo *pl)
{
	int	total;

	total = 0;
	if (pl->left)
		total += take_fork(pl, pl->left);
	if (pl->right)
		total += take_fork(pl, pl->right);
	return (total);
}

int	pl_take_fork(t_philo *pl)
{
	int	take;

	if (pl->tab->max_eat && pl->max_eat >= pl->tab->max_eat)
		return (0);
	if (!pl->rank % 2)
		take = take_right_first(pl);
	else
		take = take_left_first(pl);
	if (take < 2)
		return (-1);
	return (1);
}
