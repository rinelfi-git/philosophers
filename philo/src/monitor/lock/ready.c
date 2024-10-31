/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:12:41 by erijania          #+#    #+#             */
/*   Updated: 2024/10/31 20:21:08 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_types.h"

int pl_is_ready(t_monitor *mon)
{
    int ready;

    pthread_mutex_lock(&mon->ready_lock);
    ready = mon->is_ready;
    pthread_mutex_unlock(&mon->ready_lock);
    return (ready);
}

void pl_set_ready(t_monitor *mon, int ready)
{
    pthread_mutex_lock(&mon->ready_lock);
    mon->is_ready = ready;
    pthread_mutex_unlock(&mon->ready_lock);
}
