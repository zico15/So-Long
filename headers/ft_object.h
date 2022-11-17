/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/17 00:47:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
#define FT_OBJECT_H

#include <ft_util.h>

typedef struct s_buffer t_buffer;

typedef enum e_type
{
	OBJECT,
	MAP,
	SCENE,
	PLAYER
} t_type;

typedef struct s_object
{
	t_type		type;
	t_vector	vector;
	void		(*render)(t_buffer *buffer);
	void		(*update)();

} t_object;

#endif
