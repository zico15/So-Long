/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/17 00:44:35 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CANVA_H
# define FT_CANVA_H

# include <ft_util.h>
# include <ft_object.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_sprite
{
	void		*img;
	t_data		data;
	t_vector	v;
}	t_sprite;

typedef struct s_buffer
{
	void	*buffer;
	t_data	data;
	void	(*rectangle)(t_vector v, int color);
	void	(*rectangle_border)(t_vector v, int color, int \
	border, int color_border);
	void	(*pixel)(int x, int y, int color);
	int		(*get_color_img)(t_data	data, int x, int y);
	void	(*image)(t_sprite *sprite);
	void	(*image_pos)(t_sprite *sprite, int x1, int y1);
	void	(*image_sub)(t_sprite *sprite, t_vector sub);
	void	(*object)(t_object *ob);
	void	(*line)(t_vector begin, t_vector end, int color);
	void	(*image_resize)(t_sprite *sprite, double width, double height);
}   t_buffer;

typedef struct f_image
{
	void	(*rectangle)(void *img, t_vector vector, int color);
	void	(*pixel)(void *img, int x, int y, int color);
	void	(*txt)(char *str, t_vector v, int color);
	void	*(*new)(int w, int h);
}	t_image;


t_buffer    *canva();

#endif
