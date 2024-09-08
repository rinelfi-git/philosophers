/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_module.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:18:15 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 13:54:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_MODULE_H
# define PL_MODULE_H
# include <pthread.h>
# include <stdio.h>

typedef enum e_state	t_state;
typedef struct s_times	t_time;
typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;
enum e_state
{
	PHILO_THINKING,
	PHILO_EATING,
	PHILO_DEAD,
	PHILO_SLEEPING
};
struct s_times
{
	int	die;
	int	eat;
	int	sleep;
};
struct s_philo
{
	pthread_t	pt;
	int			id;
	int			rank;
	int			is_running;
	int			max_eat;
	void		(*run)(void *);
	t_fork		*forks[2];
	t_fork		*left;
	t_fork		*right;
	t_state		state;
	t_time		tt;
	t_table		*seat;
};
struct s_table
{
	t_fork			**forks;
	t_philo			**philos;
	t_philo			*dead;
	pthread_mutex_t	lock;
	int				length;
	int				max_eat;
	long			start;
	t_time			*tt;
};
struct s_fork
{
	pthread_mutex_t	lock;
	t_philo			*user;
};
#endif