/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:51:22 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:22:17 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_TABLE_H
# define PL_TABLE_H
# include "pl_philo.h"
# include "pl_fork.h"

typedef struct s_table
{
	t_fork	**forks;
	t_philo	**philos;
	int		length;
}	t_table;
t_table	*new_table(int length);
void	pl_init_times(t_table *tab, int *times);
#endif
