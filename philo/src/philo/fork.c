/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:43:44 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 09:42:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"
#include <unistd.h>

static int	take(t_philo *pl, t_sync *fk)
{
	pthread_mutex_lock(fk);
	pl_msg(pl, "has taken a fork");
	return (1);
}

int	pl_take_fork(t_philo *pl)
{
	int	took;

	took = 0;
	if (pl->mon->max_eat && pl->max_eat >= pl->mon->max_eat)
	{
		pl_set_state(pl, PHILO_FULL);
		return (0);
	}
	pl_update_last_meal(pl);
	if (pl->right)
		took += take(pl, pl->right);
	if (pl->left)
		took += take(pl, pl->left);
	return (took == 2 && pl_is_running(pl));
}

void	pl_free_fork(t_philo *pl)
{
	if (pl->right)
		pthread_mutex_unlock(pl->right);
	if (pl->left)
		pthread_mutex_unlock(pl->left);
}