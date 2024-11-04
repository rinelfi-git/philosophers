/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_monitor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:51:22 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 19:49:24 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_MONITOR_H
# define PL_MONITOR_H
# include "pl_types.h"

void		init_monitor(t_monitor *mon, int length);
void		pl_init_times(t_monitor *mon, int *times);
void		pl_free(t_monitor *mon);
void		pl_end(t_monitor *mon);
t_philo		*pl_get_dead(t_monitor *mon);
void		pl_set_dead(t_monitor *mon, t_philo *pl);
#endif
