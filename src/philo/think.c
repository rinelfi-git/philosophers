/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:58:29 by erijania          #+#    #+#             */
/*   Updated: 2024/09/07 12:08:52 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_philo.h"

void	pl_think(t_philo *pl, t_times *tt)
{
	pl->state = PHILO_THINKING;
	tt->eat = pl->tt.eat;
	tt->sleep = pl->tt.sleep;
	tt->die--;
}
