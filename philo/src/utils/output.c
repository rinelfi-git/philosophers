/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:56:41 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 23:37:46 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pl_types.h"
#include "pl_utils.h"

int	pl_error(char *msg, int code)
{
	while (*msg)
		write(2, msg++, 1);
	return (code);
}

void	pl_msg(t_philo *pl, char *state)
{
	t_monitor	*tab;
	long time;

	tab = pl->tab;
	time = pl_timestamp();
	pthread_mutex_lock(&tab->print_lock);
	printf("%ld %d %s\n", time - pl->tab->start, pl->rank, state);
	pthread_mutex_unlock(&tab->print_lock);
}
