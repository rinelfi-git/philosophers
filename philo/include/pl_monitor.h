/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_monitor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:51:22 by erijania          #+#    #+#             */
/*   Updated: 2024/10/27 23:09:27 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_TABLE_H
# define PL_TABLE_H
# include "pl_types.h"

void	init_monitor(t_monitor *tab, int length);
void	pl_init_times(t_monitor *tab, int *times);
void	pl_free(t_monitor *tab);
t_monitor	*to_monitor(void *obj);
void	pl_end(t_monitor *tab);
t_philo	*pl_get_dead(t_monitor *tab);
void	pl_set_dead(t_monitor *tab, t_philo *pl);
#endif
