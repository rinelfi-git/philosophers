/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:37 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 12:27:27 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_PHILO_H
# define PL_PHILO_H
# include "pl_module.h"
# define REFRESH_INTERVAL 1
# define EXEC_INTERVAL 500

t_philo		*new_philo(int rank);
t_philo		*to_philo(void *obj);
pthread_t	*to_thread(void *obj);
int			philosopher(t_table *tab);
void		pl_take_fork(t_philo *pl);
void		pl_free_fork(t_philo *pl);
void		pl_eat(t_philo *pl, t_time *tt);
void		pl_sleep(t_philo *pl, t_time *tt);
void		pl_think(t_philo *pl, t_time *tt);
void		pl_set_times(void *pl, int *times);
void		pl_check_state(t_philo *pl, t_time *tt);
void		*pl_exec(void *self);
#endif
