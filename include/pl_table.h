/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:51:22 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 21:24:02 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PL_TABLE_H
# define PL_TABLE_H

typedef struct s_table
{
	void	**forks;
	void	**philos;
	int		length;
	int		max_eat;
}	t_table;
t_table	*new_table(int length);
void	pl_init_times(t_table *tab, int *times);
void	pl_free(void *pl);
t_table	*to_table(void *obj);
void	pl_stop(t_table *tab);
#endif
