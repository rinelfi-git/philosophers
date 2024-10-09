/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:28:05 by erijania          #+#    #+#             */
/*   Updated: 2024/10/09 19:29:27 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"

t_philo	*pl_get_dead(t_table *tab)
{
	t_philo	*pl;

	pl = 0;
	pthread_mutex_lock(&tab->dead_lock);
	pl = tab->dead;
	pthread_mutex_unlock(&tab->dead_lock);
	return (pl);
}
