/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/17 01:04:55 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
#define FT_OBJECT_H

#include <ft_util.h>
#include <ft_animation.h>

typedef struct s_buffer t_buffer;
typedef struct s_sprite t_sprite;
typedef struct s_object t_object;

typedef enum e_type
{
	OBJECT,
	MAP,
	SCENE,
	PLAYER
} t_type;

struct s_object
{
	t_type			type;
	t_vector		vector;
	t_animation		animation;
	double			life;
	void			(*render)(t_buffer *buffer);
	void			(*update)();
	void			(*destroy)();
	void			(*funct_key)(char *key, int type_event);
	void			(*funct_mouse)(int x, int y, int type_event);
	void			(*collision)(t_object *collided);
	int				(*set_position)(t_vector v);
	t_sprite		*(*get_sprite)();
	int				(*damage)(double	d);

};

#endif
