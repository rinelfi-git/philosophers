/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_fork.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:34:42 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:30:56 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_FORK_H
# define PL_FORK_H
# include <pthread.h>
# include "pl_philo.h"

typedef struct s_fork
{
	pthread_mutex_t	mt;
	t_philo			*user;
}	t_fork;
t_fork	*new_fork(void);
#endif
