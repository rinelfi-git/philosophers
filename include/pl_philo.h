/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:37 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 15:35:16 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_PHILO_H
# define PL_PHILO_H
# define EXEC_INTERVAL 10
# include "pl_module.h"

t_philo		*new_philo(int rank, t_fork *left);
t_philo		*to_philo(void *obj);
pthread_t	*to_thread(void *obj);
int			philosopher(t_table *tab);
void		pl_take_fork(t_philo *pl);
void		pl_free_fork(t_philo *pl);
void		pl_eat(t_philo *pl, long curr_time);
void		pl_sleep(t_philo *pl, long curr_time);
void		pl_think(t_philo *pl, long curr_time);
void		pl_check_state(t_philo *pl);
void		*pl_exec(void *self);
#endif
