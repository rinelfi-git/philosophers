/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:37:13 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 23:11:38 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_fork.h"

t_fork	*to_fork(void *obj)
{
	return ((t_fork *)obj);
}

void	init_fork(t_fork *fk)
{
	pthread_mutex_init(&fk->use_lock, 0);
	fk->user = 0;
}
