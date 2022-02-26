/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:26:59 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 18:30:20 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRITES_H
# define FT_SPRITES_H

# include "ft_so_long.h"

# define MAX_ANIMATIONS 9

typedef enum s_type_animation
{
	STOPPED,
	WALKING_W,
	WALKING_S,
	WALKING_A,
	WALKING_D,
	ATTACK_A,
	ATTACK_B,
	ATTACK_C,
	DEAD
}	t_type_animation;

typedef struct s_mlx_img_list
{
	int						width;
	int						height;
	char					*buffer;
	float					vertexes[8];
	struct s_mlx_img_list	*next;
}	t_mlx_img;

typedef struct s_image
{
	void			*img;
	int				width;
	int				height;
	int				bits;
	int				size;
	int				endian;
	void			*pixels;
	int				size_w;
	int				size_h;
	int				x_o;
	int				y_o;
	int				x;
	int				y;
}	t_image;

typedef struct s_sprites
{
	void		**imgs;
	int			index;
	int			size;
}	t_sprites;

typedef struct s_animaton
{
	struct s_mlx_img_list	*img;
	struct s_mlx_img_list	*img_selct;
	int						is_repeat;
}	t_animation;

typedef struct s_animator
{
	t_type_animation	type;
	int					time;
	float				time_max;
	float				is_animation;
	struct s_animaton	*animation;
	struct s_animaton	list[10];

}	t_animator;

#endif
