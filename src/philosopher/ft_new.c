/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:51 by erijania          #+#    #+#             */
/*   Updated: 2024/07/19 09:35:43 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>

t_phylosopher	*ft_new_philosopher(int rank)
{
	t_phylosopher	*ft;

	ft = (t_phylosopher *)malloc(sizeof(t_phylosopher));
	if (!ft)
		exit(1);
	ft->rank = rank;
	return (ft);
}
