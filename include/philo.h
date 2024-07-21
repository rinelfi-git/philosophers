/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:37 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 15:21:01 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>

enum
{
	PHILO_THINKING = 0,
	PHILO_EATIN = 1,
	PHILO_SLEEPING = 2
};
typedef struct	s_philo
{
	pthread_t	thread;
	void		(*run)(void *);
	void		(*stop)(void *);
	int			rank;
	int			state;
}	t_philo;
t_philo		*pl_new(int rank);
t_philo		*to_philo(void *obj);
pthread_t	*to_thread(void *obj);
#endif
