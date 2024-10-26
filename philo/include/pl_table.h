/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:51:22 by erijania          #+#    #+#             */
/*   Updated: 2024/10/26 17:49:08 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_TABLE_H
# define PL_TABLE_H
# include "pl_types.h"

void	init_table(t_table *tab, int length);
void	pl_init_times(t_table *tab, int *times);
void	pl_free(t_table *tab);
t_table	*to_table(void *obj);
void	pl_end(t_table *tab);
t_philo	*pl_get_dead(t_table *tab);
void	pl_set_dead(t_table *tab, t_philo *pl);
#endif
