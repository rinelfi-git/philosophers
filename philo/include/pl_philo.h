/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:37 by erijania          #+#    #+#             */
/*   Updated: 2024/11/04 09:38:52 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_PHILO_H
# define PL_PHILO_H
# include "pl_types.h"

void	init_philo(t_philo *pl, int rank, t_sync *left);
int		philosopher(t_monitor *tab);
int		pl_take_fork(t_philo *pl);
void	pl_free_fork(t_philo *pl);
void	*pl_routine(void *self);
t_state	pl_get_state(t_philo *pl);
void	pl_set_run(t_philo *pl, int run);
int		pl_is_running(t_philo *pl);
void	pl_set_state(t_philo *pl, t_state state);
void	pl_update_last_meal(t_philo *pl);
long	pl_get_last_meal(t_philo *pl);
#endif
