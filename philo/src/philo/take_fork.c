/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:48:51 by erijania          #+#    #+#             */
/*   Updated: 2024/09/20 19:20:44 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_fork.h"
#include "pl_utils.h"

static void	take_left_first(t_philo *pl)
{
	long	interval;

	interval = pl_utl_time() - pl->seat->start;
	if (!pl->left->user)
	{
		pthread_mutex_lock(&pl->left->lock);
		pl->left->user = pl;
		printf("%ld %d has taken a fork\n", interval, pl->rank);
	}
	if (!pl->right->user)
	{
		pthread_mutex_lock(&pl->right->lock);
		pl->right->user = pl;
		printf("%ld %d has taken a fork\n", interval, pl->rank);
	}
}
static void	take_right_first(t_philo *pl)
{
	long	interval;

	interval = pl_utl_time() - pl->seat->start;
	if (!pl->right->user)
	{
		pthread_mutex_lock(&pl->right->lock);
		pl->right->user = pl;
		printf("%ld %d has taken a fork\n", interval, pl->rank);
	}
	if (!pl->left->user)
	{
		pthread_mutex_lock(&pl->left->lock);
		pl->left->user = pl;
		printf("%ld %d has taken a fork\n", interval, pl->rank);
	}
}

static int	can_use_fork(t_philo *pl)
{
	return (pl->left != pl->right
		&& pl->left->user == pl && pl->right->user == pl);
}

void	pl_take_fork(t_philo *pl)
{
	if (pl->rank % 2 == 0)
		take_right_first(pl);
	else
		take_left_first(pl);
	if (can_use_fork(pl) && !is_max_eat_exceeded(pl))
	{
		pl->state = PHILO_EATING;
		pl->tt.die = pl->seat->tt->die + pl_utl_time();
		pl->max_eat++;
	}
}
