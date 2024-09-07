/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:49:22 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 11:33:23 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_UTILS_H
# define PL_UTILS_H
# include "pl_philo.h"

int		pl_utl_atoi(const char *str);
void	pl_utl_lst_foreach(t_philo **lst, void (*call)());
int		pl_utl_error(char *msg, int code);
long	pl_utl_time(void);
#endif
