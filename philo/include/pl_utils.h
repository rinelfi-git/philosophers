/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:49:22 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 15:10:47 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_UTILS_H
# define PL_UTILS_H
# include "pl_philo.h"

long	ft_atoi(const char *str);
int		print_error(char *msg, int code);
int		ft_isnumber(char *str);
void	list_foreach(t_monitor *monitor, void (*call)());
long	get_timestamp(void);
int		ft_isinteger(char *str);
void	print_state(t_philo *pl, char *state);
int		sleep_while(t_philo *pl, long ms);
#endif
