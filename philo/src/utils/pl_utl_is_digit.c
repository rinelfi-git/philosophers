/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utl_is_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:37:26 by erijania          #+#    #+#             */
/*   Updated: 2024/09/21 11:24:57 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "pl_utils.h"

int	pl_utl_is_number(char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (*str == 0);
}

int	pl_utl_is_integer(char *str)
{
	long	nbr;

	nbr = pl_utl_atoi(str);
	if (nbr > (long) INT_MAX || nbr < (long) INT_MIN)
		return (0);
	return (1);
}
