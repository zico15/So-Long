/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 02:41:14 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CANVA_H
# define FT_CANVA_H

# include <ft_object.h>

typedef struct s_vector	t_vector;

typedef struct s_sprite
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_buffer
{
	void		*buffer;
	t_sprite	data;
	void		(*rectangle)(t_vector v, int color);
	void		(*rectangle_border)(t_vector v, int color, int \
	border, int color_border);
	bool		(*pixel)(int x, int y, int color);
	int			(*get_color)(t_sprite	*sprite, int x, int y);
	void		(*image)(t_sprite *sprite, int x, int y);
	void		(*image_pos)(t_sprite *sprite, int x1, int y1);
	void		(*image_sub)(t_sprite *sprite, int x, int y, t_vector v1);
	void		(*object)(t_object *ob);
	void		(*line)(t_vector begin, t_vector end, int color);
	void		(*image_resize)(t_sprite *sprite, double width, double height);
	t_sprite	*(*load)(char *filename);
}	t_buffer;

typedef struct f_image
{
	void	(*rectangle)(void *img, t_vector vector, int color);
	void	(*pixel)(void *img, int x, int y, int color);
	void	(*txt)(char *str, t_vector v, int color);
	void	*(*new)(int w, int h);
}	t_image;

void		init_canva(void);
t_buffer	*canva(void);

#endif
