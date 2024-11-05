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
# define EXEC_INTERVAL 50
# define EVEN_WAIT_START 15000
# define MONITOR_WAIT 5
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
	PHILO_FULL,
	PHILO_DEAD,
};
struct						s_times
{
	long					die;
	long					eat;
	long					sleep;
};
struct						s_philo
{
	pthread_t				thread;
	t_sync					state_lock;
	t_sync					run_lock;
	t_sync					last_meal_lock;
	int						rank;
	int						is_running;
	int						eat_times;
	void					(*stop_job)(void *);
	t_sync					*left_fork;
	t_sync					*right_fork;
	int						taken_fork;
	t_state					state;
	long					last_meal;
	t_monitor				*monitor;
};
struct						s_monitor
{
	t_sync					dead_lock;
	t_sync					print_lock;
	t_sync					*fork_list;
	t_philo					*philosopher_list;
	t_philo					*dead;
	int						size;
	int						eat_limit;
	int						ate_number;
	long					start_time;
	t_time					time_to;
};
#endif