/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:40:06 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 15:58:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	pl_char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

int	pl_atoi(char *str)
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
	while (pl_char_to_digit(*str) >= 0)
	{
		ret = ret * 10;
		ret += pl_char_to_digit(*(str++));
	}
	return (ret * sign);
}
