/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:37 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 10:30:09 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_PHILO_H
# define PL_PHILO_H
# include "pl_table.h"
# include "pl_fork.h"
# include <pthread.h>
# include <stdio.h>

typedef enum e_pl_state
{
	PHILO_THINKING,
	PHILO_EATING,
	PHILO_SLEEPING
}	t_pl_state;
typedef struct s_philo
{
	pthread_t	pt;
	void		(*run)(void *);
	void		(*stop)(void *);
	t_pl_state	state;
	t_fork		*forks[2];
	int			is_running;
	int			rank;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
	int			max_eat;
}	t_philo;
t_philo		*pl_new(int rank, int *times);
t_philo		*to_philo(void *obj);
pthread_t	*to_thread(void *obj);
int			philosopher(t_philo **lst);
void		pl_take_fork(t_philo *pl, t_table *tab);
void		pl_free_fork(t_philo *pl);
void		pl_eat(t_philo *pl);
#endif
