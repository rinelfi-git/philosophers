/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utl_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:48:24 by erijania          #+#    #+#             */
/*   Updated: 2024/09/25 18:19:21 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"
#include "pl_utils.h"
#include <stdio.h>

void	pl_utl_message(t_philo *pl, char *state)
{
	long	time;
	t_table	*tab;

	time = pl_utl_timestamp();
	tab = pl->tab;
	pthread_mutex_lock(&tab->print_lock);
	printf("%ld %d %s\n", time - tab->start, pl->rank, state);
	pthread_mutex_unlock(&tab->print_lock);
}