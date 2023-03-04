/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:35 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 02:41:28 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva.h>

void		__image_pos(t_sprite *sprite, int x, int y);
void		__draw_line(t_vector begin, t_vector end, int color);
void		__image_resize(t_sprite *sprite, double width, double height);
void		__rectangle(t_vector v, int color);
void		__rectangle_border(t_vector v, int color, int border, \
int color_border);
bool		__pixel(int x, int y, int color);
void		__image(t_sprite *sprite, int x, int y);
void		__image_sub(t_sprite *sprite, int x, int y, t_vector v1);
int			__get_color(t_sprite *sprite, int x, int y);

t_sprite	*__load(char *filename)
{
	t_sprite	*sprite;

	sprite = malloc_ob(sizeof(t_sprite));
	sprite->img = mlx_xpm_file_to_image(engine()->mlx, filename, \
	&sprite->width, &sprite->height);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bits_per_pixel, \
	&sprite->line_length, &sprite->endian);
	return (sprite);
}

t_buffer	*canva(void)
{
	static t_buffer	b;

	return (&b);
}

void	init_canva(void)
{
	canva()->data.width = engine()->width;
	canva()->data.height = engine()->height;
	(canva()->data.img) = mlx_new_image(engine()->mlx, engine()->width, \
	engine()->height);
	(canva()->data.addr) = mlx_get_data_addr(canva()->data.img, \
	&canva()->data.bits_per_pixel, \
	&canva()->data.line_length, &canva()->data.endian);
	canva()->rectangle = __rectangle;
	canva()->pixel = __pixel;
	canva()->image = __image;
	canva()->image_sub = __image_sub;
	canva()->rectangle_border = __rectangle_border;
	canva()->image_pos = __image_pos;
	canva()->image_resize = __image_resize;
	canva()->get_color = __get_color;
	canva()->load = __load;
}


/**
 * retorna false se possicao x ou y estiver fora da canva
 * **/
bool	__pixel(int x, int y, int color)
{
	char		*dst;
	t_sprite	*data;

	if (color == COLOR_TRANSPARENT)
		return (true);
	if (x >= canva()->data.width || x < 0 || y < 0 || y >= canva()->data.height)
		return (false);
	data = &(canva()->data);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (true);
}

int	__get_color(t_sprite *sprite, int x, int y)
{
	char	*dst;
	int		color;

	dst = sprite->addr + (y * sprite->line_length + x * \
	(sprite->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}
