/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:49:06 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 23:25:20 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_free_fork(t_philo *pl)
{
	if (pl->left->user == pl)
	{
		pl->left->user = 0;
		pthread_mutex_unlock(&pl->left->lock);
	}
	if (pl->right->user == pl)
	{
		pl->right->user = 0;
		pthread_mutex_unlock(&pl->right->lock);
	}
	pl->state = PHILO_SLEEPING;
}
