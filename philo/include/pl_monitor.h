/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_monitor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:51:22 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 15:06:35 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_MONITOR_H
# define PL_MONITOR_H
# include "pl_types.h"

void		monitor_init(t_monitor *monitor, int size);
void		free_ressources(t_monitor *monitor);
void		stop_everything(t_monitor *monitor);
t_philo		*monitor_get_dead(t_monitor *monitor);
void		monitor_set_dead(t_monitor *monitor, t_philo *philo);
#endif
