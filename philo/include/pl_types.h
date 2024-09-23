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

#ifndef pl_types_H
# define pl_types_H
# define EXEC_INTERVAL 100
# define WAIT_START 400
# define TT_THINK 1
# include <pthread.h>
# include <stdio.h>

typedef enum e_state	t_state;
typedef struct s_times	t_time;
typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;
enum e_state
{
	PHILO_NONE,
	PHILO_THINKING,
	PHILO_EATING,
	PHILO_DEAD,
	PHILO_SLEEPING
};
struct s_times
{
	long	die;
	long	eat;
	long	sleep;
	long	think;
};
struct s_philo
{
	pthread_t	thread;
	int			id;
	int			rank;
	int			is_running;
	int			max_eat;
	void		(*run)(void *);
	void		(*stop)(void *);
	t_fork		*left;
	t_fork		*right;
	t_state		state;
	t_time		tt;
	t_table		*tab;
};
struct s_table
{
	t_fork			*forks;
	t_philo			*philos;
	t_philo			*dead;
	pthread_mutex_t	dead_lock;
	int				length;
	int				max_eat;
	long			start;
	t_time			tt;
};
struct s_fork
{
	pthread_mutex_t	lock;
	t_philo			*user;
};
#endif