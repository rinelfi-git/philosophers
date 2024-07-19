/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:37 by erijania          #+#    #+#             */
/*   Updated: 2024/07/19 09:35:23 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

enum
{
	PHILO_THINKING = 0,
	PHILO_EATIN = 1,
	PHILO_SLEEPING = 2
};
typedef struct s_phylosopher	t_phylosopher;
struct s_phylosopher
{
	int	rank;
	int	state;

};
#endif
