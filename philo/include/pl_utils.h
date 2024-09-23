/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:49:22 by erijania          #+#    #+#             */
/*   Updated: 2024/09/21 11:26:24 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_UTILS_H
# define PL_UTILS_H
# include "pl_philo.h"

long	pl_utl_atoi(const char *str);
int		pl_utl_error(char *msg, int code);
int		pl_utl_is_number(char *str);
void	pl_utl_lst_foreach(t_table *tab, void (*call)());
long	pl_utl_time(void);
int		pl_utl_is_integer(char *str);
#endif