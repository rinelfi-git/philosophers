/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:56:41 by erijania          #+#    #+#             */
/*   Updated: 2024/10/31 20:04:04 by erijania         ###   ########.fr       */
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

int	pl_error(char *msg, int code)
{
	while (*msg)
		write(2, msg++, 1);
	return (code);
}

void	pl_msg(t_philo *pl, char *state)
{
	t_monitor	*tab;

	tab = pl->mon;
	pthread_mutex_lock(&tab->print_lock);
	pl_putnbr(pl_timestamp() - pl->mon->start);
	pl_putchar(' ');
	pl_putnbr(pl->rank);
	pl_putchar(' ');
	pl_putstr(state);
	pl_putchar('\n');
	pthread_mutex_unlock(&tab->print_lock);
}
