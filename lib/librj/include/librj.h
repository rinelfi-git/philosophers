/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librj.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:06:08 by erijania          #+#    #+#             */
/*   Updated: 2024/07/21 17:41:20 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRJ_H
# define LIBRJ_H

typedef char*	t_str;
typedef struct s_obj
{
	void	(*destroy)(void *);
}	t_obj;
t_obj	*to_obj(void *obj);
#endif
