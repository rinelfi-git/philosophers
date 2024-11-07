/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:56:41 by erijania          #+#    #+#             */
/*   Updated: 2024/11/07 15:19:51 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pl_types.h"
#include "pl_utils.h"

static void	pl_putchar(char c)
{
	write(1, &c, 1);
}

static void	pl_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static void	pl_putnbr(long nbr)
{
	if (nbr < 0)
	{
		pl_putchar('-');
		pl_putnbr(-nbr);
	}
	else if (nbr >= 10)
	{
		pl_putnbr(nbr / 10);
		pl_putchar('0' + nbr % 10);
	}
	else
		pl_putchar('0' + nbr);
}

int	print_error(char *msg, int code)
{
	while (*msg)
		write(2, msg++, 1);
	return (code);
}

void	print_state(t_philo *philo, char *state)
{
	t_monitor	*mon;
	long		time;

	if (!philo)
	{
		pl_putstr(state);
		return ;
	}
	mon = philo->monitor;
	time = get_timestamp();
	pthread_mutex_lock(&mon->print_lock);
	pl_putnbr(time - philo->monitor->start_time);
	pl_putchar(' ');
	pl_putnbr(philo->rank);
	pl_putchar(' ');
	pl_putstr(state);
	pl_putchar('\n');
	pthread_mutex_unlock(&mon->print_lock);
}
