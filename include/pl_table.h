/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:51:22 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 15:23:24 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_TABLE_H
# define PL_TABLE_H

typedef struct s_table
{
	void	**forks;
	void	**philos;
	int		length;
}	t_table;
t_table	*new_table(int length);
void	pl_init_times(t_table *tab, int *times);
void	pl_free(void *pl);
#endif
