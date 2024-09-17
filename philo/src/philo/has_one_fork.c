/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_one_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:21:24 by erijania          #+#    #+#             */
/*   Updated: 2024/09/17 20:24:33 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pl_module.h"

int	pl_has_one_fork(t_philo *pl)
{
	int	left_only;
	int	right_only;

	left_only = pl->left->user == pl && pl->right->user != pl;
	right_only = pl->left->user != pl && pl->right->user == pl;
	return (left_only || right_only);
}
