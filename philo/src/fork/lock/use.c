/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:13:53 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 23:19:23 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"

void	pl_set_fork_use(t_fork *fk, t_philo *user)
{
	pthread_mutex_lock(&fk->use_lock);
	fk->user = user;
	pthread_mutex_unlock(&fk->use_lock);
}

t_philo	*pl_get_fork_user(t_fork *fk)
{
	t_philo *pl;

	pl = 0;
	pthread_mutex_lock(&fk->use_lock);
	pl = fk->user;
	pthread_mutex_unlock(&fk->use_lock);
	return (pl);
}
