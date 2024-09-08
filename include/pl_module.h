/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_module.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:18:15 by erijania          #+#    #+#             */
/*   Updated: 2024/09/08 12:31:42 by erijania         ###   ########.fr       */
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
	int			rank;
	int			is_running;
	int			max_eat;
	void		(*run)(void *);
	t_fork		*forks[2];
	t_state		state;
	t_time		tt;
	t_table		*seat;
};
struct s_table
{
	void	**forks;
	void	**philos;
	int		length;
	int		max_eat;
	long	start;
	t_time	*tt;
};
struct s_fork
{
	pthread_mutex_t	locker;
	t_philo			*philo;
};
#endif