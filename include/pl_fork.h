/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_fork.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:34:42 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 13:23:29 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_FORK_H
# define PL_FORK_H
# include <pthread.h>

typedef struct s_fork
{
	pthread_mutex_t	mt;
	void			*user;
}	t_fork;
t_fork	*new_fork(void);
t_fork	*to_fork(void *obj);
#endif
