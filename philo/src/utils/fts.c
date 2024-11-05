/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:26:24 by erijania          #+#    #+#             */
/*   Updated: 2024/11/05 15:10:27 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

long	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	sign = 1;
	ret = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (char_to_digit(*str) >= 0)
	{
		ret = ret * 10;
		ret += char_to_digit(*(str++));
	}
	return (ret * sign);
}

int	ft_isnumber(char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (*str == 0);
}

int	ft_isinteger(char *str)
{
	long	nbr;

	nbr = ft_atoi(str);
	if (nbr > (long) INT_MAX || nbr < (long) INT_MIN)
		return (0);
	return (1);
}
