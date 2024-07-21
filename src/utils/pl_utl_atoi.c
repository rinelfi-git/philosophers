/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utl_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:40:06 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 17:09:39 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librj.h"

static int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

int	pl_utl_atoi(t_str str)
{
	int	ret;
	int	sign;

	sign = 1;
	ret = 0;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (char_to_digit(*str) >= 0)
	{
		ret = ret * 10;
		ret += char_to_digit(*(str++));
	}
	return (ret * sign);
}
