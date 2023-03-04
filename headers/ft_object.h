/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 03:54:30 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
# define FT_OBJECT_H

# include	<ft_util.h>
# include	<ft_animation.h>
# include   <ft_canva.h>

typedef struct s_buffer	t_buffer;
typedef struct s_sprite	t_sprite;
typedef struct s_object	t_object;
typedef struct s_player	t_player;
typedef struct s_scene	t_scene;
typedef struct s_map	t_map;

typedef enum e_type
{
	OBJECT,
	MAP,
	SCENE,
	PLAYER
}	t_type;

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

struct s_scene
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
	void			(*add)(t_object *ob);
	void			*objects;
	void			*event_keys;
	void			*event_render;
	void			*event_update;
};

struct s_player
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

struct s_map
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
	int				(*load)(char *path);
	char			**map;

};

t_object	*new_map(void);
t_map		*map(void);
t_object	*new_player(void);
t_scene		*new_scene(void);

#endif
