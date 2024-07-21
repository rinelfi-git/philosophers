/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:04 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 20:59:51 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_utils.h"
#include <stdlib.h>
#include <unistd.h>

int	philosopher(t_philo **lst)
{
	pl_utl_lst_foreach(lst, free);
	return (0);
}
