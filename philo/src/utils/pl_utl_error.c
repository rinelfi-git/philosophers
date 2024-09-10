/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utl_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:56:41 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 20:25:16 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	pl_utl_error(char *msg, int code)
{
	while (*msg)
		write(2, msg++, 1);
	return (code);
}
