/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utl_lst_foreach.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:38:08 by erijania          #+#    #+#             */
/*   Updated: 2024/08/15 15:18:29 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pl_utl_lst_foreach(t_philo **lst, void (*call)())
{
	unsigned int	i;

	if (!lst)
		return ;
	i = 0;
	while (lst[i])
	{
		call(lst[i], i);
		i++;
	}
}
