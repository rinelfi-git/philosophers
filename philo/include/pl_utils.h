/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:49:22 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 14:36:30 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_UTILS_H
# define PL_UTILS_H
# include "pl_philo.h"

long	pl_atoi(const char *str);
int		pl_error(char *msg, int code);
int		pl_isnumber(char *str);
void	pl_utl_lst_foreach(t_monitor *tab, void (*call)());
long	pl_timestamp(void);
int		pl_isinteger(char *str);
void	pl_msg(t_philo *pl, char *state);
int		pl_usleep(t_philo *pl, long ms);
#endif
