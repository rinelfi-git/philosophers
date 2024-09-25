/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:49:06 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 18:42:00 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_free_fork(t_philo *pl)
{
	int	freed;

	freed = 0;
	pthread_mutex_lock(&pl->left->use_lock);
	if (pl->left->user == pl)
	{
		pl->left->user = 0;
		freed++;
	}
	pthread_mutex_unlock(&pl->left->use_lock);
	pthread_mutex_lock(&pl->right->use_lock);
	if (pl->right->user == pl)
	{
		pl->right->user = 0;
		freed++;
	}
	pthread_mutex_unlock(&pl->right->use_lock);
	if (pl->state == PHILO_EATING && freed == 2)
		pl->state = PHILO_SLEEPING;
}
