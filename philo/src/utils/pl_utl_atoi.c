/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utl_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:40:06 by erijania          #+#    #+#             */
/*   Updated: 2024/09/21 11:22:44 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

long	pl_utl_atoi(const char *str)
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
