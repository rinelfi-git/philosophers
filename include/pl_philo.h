/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:37 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 09:57:10 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_PHILO_H
# define PL_PHILO_H
# include "pl_table.h"
# include "pl_fork.h"
# include <pthread.h>
# include <stdio.h>
# define REFRESH_INTERVAL 1
# define EXEC_INTERVAL 500

typedef enum e_pl_state
{
	PHILO_THINKING,
	PHILO_EATING,
	PHILO_DEAD,
	PHILO_SLEEPING
}	t_pl_state;
typedef struct s_times
{
	int	die;
	int	eat;
	int	sleep;
}	t_times;
typedef struct s_philo
{
	pthread_t	pt;
	int			rank;
	int			is_running;
	int			max_eat;
	void		(*run)(void *);
	void		*forks[2];
	t_pl_state	state;
	t_times		tt;
	t_table		*seat;
}	t_philo;
t_philo		*new_philo(int rank);
t_philo		*to_philo(void *obj);
pthread_t	*to_thread(void *obj);
int			philosopher(t_table *tab);
void		pl_take_fork(t_philo *pl);
void		pl_free_fork(t_philo *pl);
void		pl_eat(t_philo *pl, t_times *tt);
void		pl_sleep(t_philo *pl, t_times *tt);
void		pl_think(t_philo *pl, t_times *tt);
void		pl_set_times(void *pl, int *times);
void		pl_check_state(t_philo *pl, t_times *tt);
void		*pl_exec(void *self);
#endif
