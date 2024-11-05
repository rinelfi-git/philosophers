/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:37 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 15:08:08 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_PHILO_H
# define PL_PHILO_H
# include "pl_types.h"

void	philosopher_init(t_philo *philo, int rank, t_sync *fork);
int		execution(t_monitor *monitor);
int		do_take_fork(t_philo *philo);
void	do_free_fork(t_philo *philo);
void	*philosopher_routine(void *self);
t_state	get_philo_state(t_philo *philo);
void	philosopher_set_run(t_philo *philo, int run);
int		philosopher_get_run(t_philo *philo);
void	set_philo_state(t_philo *philo, t_state state);
void	update_last_meal(t_philo *philo);
long	get_last_meal(t_philo *philo);
#endif
