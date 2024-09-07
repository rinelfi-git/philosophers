/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:37:13 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 15:39:10 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_fork.h"
#include <stdlib.h>

t_fork	*new_fork(void)
{
	t_fork	*new;

	new = (t_fork *)malloc(sizeof(t_fork));
	if (!new)
		exit(1);
	pthread_mutex_init(&new->locker, 0);
	new->user = 0;
	return (new);
}
