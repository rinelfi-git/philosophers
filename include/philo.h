/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:37 by erijania          #+#    #+#             */
/*   Updated: 2024/07/19 14:24:05 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>

enum
{
	PHILO_THINKING = 0,
	PHILO_EATIN = 1,
	PHILO_SLEEPING = 2
};
typedef struct s_philo	t_philo;
struct s_philo
{
	pthread_t	thread;
	void		(*run)(void *);
	void		(*stop)(void *);
	int			rank;
	int			state;
};
t_philo	*n_philo(int r);
t_philo	*to_philo(void *v);
#endif
