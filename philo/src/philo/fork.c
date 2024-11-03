/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:43:44 by erijania          #+#    #+#             */
/*   Updated: 2024/11/03 21:58:37 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"
#include <unistd.h>

static void	take(t_philo *pl, t_sync *fk)
{
	pthread_mutex_lock(fk);
	pl_msg(pl, "has taken a fork");
}

int	pl_take_fork(t_philo *pl)
{
	if (pl->mon->max_eat && pl->max_eat >= pl->mon->max_eat)
	{
		pl_set_state(pl, PHILO_FULL);
		return (0);
	}
	if (pl->right)
		take(pl, pl->right);
	if (pl->left)
		take(pl, pl->left);
	return (1);
}

void	pl_free_fork(t_philo *pl)
{
	if (pl->right)
		pthread_mutex_unlock(pl->right);
	if (pl->left)
		pthread_mutex_unlock(pl->left);
}