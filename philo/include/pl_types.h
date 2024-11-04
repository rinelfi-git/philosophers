/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:18:15 by erijania          #+#    #+#             */
/*   Updated: 2024/09/21 12:33:01 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_TYPES_H
# define PL_TYPES_H
# define EXEC_INTERVAL 100
# define EVEN_WAIT_START 30000
# define MONITOR_WAIT 10
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_state		t_state;
typedef struct s_times		t_time;
typedef struct s_philo		t_philo;
typedef struct s_monitor	t_monitor;
typedef pthread_mutex_t		t_sync;
enum						e_state
{
	PHILO_NONE,
	PHILO_STOP,
	PHILO_FULL,
	PHILO_DEAD,
};
struct						s_times
{
	long					die;
	long					eat;
	long					sleep;
	long					think;
	long					start;
};
struct						s_philo
{
	pthread_t				thread;
	t_sync					self_lock;
	t_sync					state_lock;
	t_sync					run_lock;
	t_sync					last_meal_lock;
	int						rank;
	int						is_running;
	int						max_eat;
	long					start;
	void					(*stop)(void *);
	t_sync					*left;
	t_sync					*right;
	t_state					state;
	t_time					tt;
	long					last_meal;
	t_monitor				*mon;
};
struct						s_monitor
{
	t_sync					self_lock;
	t_sync					dead_lock;
	t_sync					print_lock;
	t_sync					*forks;
	t_philo					*philos;
	t_philo					*dead;
	int						length;
	int						max_eat;
	int						nbr_ate;
	long					start;
	t_time					tt;
};
#endif