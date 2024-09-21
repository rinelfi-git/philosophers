/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_fork.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:34:42 by erijania          #+#    #+#             */
/*   Updated: 2024/09/21 12:36:53 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_FORK_H
# define PL_FORK_H
# include "pl_types.h"

t_fork	*new_fork(void);
t_fork	*to_fork(void *obj);
#endif
