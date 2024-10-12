/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:49:06 by erijania          #+#    #+#             */
/*   Updated: 2024/10/12 16:15:46 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"
#include "pl_utils.h"

static void	free_left(t_philo *pl, int *freed)
{
	pthread_mutex_lock(&pl->left->use_lock);
	if (pl->left->user == pl)
	{
		pl->left->user = 0;
		(*freed)++;
	}
	pthread_mutex_unlock(&pl->left->use_lock);
}

static void	free_right(t_philo *pl, int *freed)
{
	pthread_mutex_lock(&pl->right->use_lock);
	if (pl->right->user == pl)
	{
		pl->right->user = 0;
		(*freed)++;
	}
	pthread_mutex_unlock(&pl->right->use_lock);
}

void	pl_free_fork(t_philo *pl)
{
	int	freed;

	freed = 0;
	if (pl->left)
		free_left(pl, &freed);
	if (pl->right)
		free_right(pl, &freed);
	pthread_mutex_lock(&pl->state_lock);
	if (pl->state == PHILO_EATING && freed == 2)
		pl->state = PHILO_SLEEPING;
	pthread_mutex_unlock(&pl->state_lock);
}
