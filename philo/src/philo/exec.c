/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:16:14 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 18:11:35 by erijania         ###   ########.fr       */
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
	int		take;

	pl = to_philo(self);
	while (!pl_is_running(pl))
		usleep(WAIT_START);
	while (1)
	{
		take = pl_take_fork(pl);
		while (take == -1)
			take = pl_take_fork(pl);
		if (take == 0)
			break ;
		if (!pl_eating(pl))
			break ;
		if (!pl_sleeping(pl))
			break ;
	}
	pl->stop(pl);
	return (0);
}
