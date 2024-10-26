/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/10/26 18:07:22 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"
#include "pl_table.h"
#include <unistd.h>
#include <stdlib.h>

void	*pl_exec(void *self)
{
	t_philo	*pl;

	pl = to_philo(self);
	while (!pl_is_running(pl))
		usleep(WAIT_START);
	while (pl_is_running(pl))
	{
		if (!pl_take_fork(pl))
			break ;
		if (!pl_eating(pl))
			break ;
		if (!pl_sleeping(pl))
			break ;
	}
	pl->stop(pl);
	return (0);
}
