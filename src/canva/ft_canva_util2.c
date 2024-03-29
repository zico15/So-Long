/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:34:45 by nprimo            #+#    #+#             */
/*   Updated: 2023/03/04 02:09:21 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva.h>

bool	__pixel(int x, int y, int color);
int		__get_color(t_sprite *sprite, int x, int y);

void	__rectangle(t_vector v, int color)
{
	int			x;

	v.w += v.x;
	v.h += v.y;
	while (v.y < v.h)
	{
		x = v.x;
		while (x < v.w)
		{
			__pixel(x++, v.y, color);
		}
		v.y++;
	}
}

void	__rectangle_border(t_vector v, int color, int border, int color_border)
{
	int			x;
	t_vector	v_b;

	v.w += v.x;
	v.h += v.y;
	v_b = vector(v.x + border, v.y + border, v.w - border, v.h - border);
	while (v.y < v.h)
	{
		x = v.x;
		while (x < v.w)
		{
			if (x <= v_b.x || x >= v_b.w || (v.y <= v_b.y || v.y >= v_b.h))
				__pixel(x++, v.y, color_border);
			else
				__pixel(x++, v.y, color);
		}
		v.y++;
	}
}

void	__image_resize(t_sprite *sprite, double width, double height)
{
	t_vector	v;
	int			x;
	int			y;

	v.y = 0;
	y = -1;
	v.w = ((double) sprite->width / width);
	v.h = ((double) sprite->height / height);
	while (++y < (int) height)
	{
		v.x = 0;
		x = -1;
		while (++x < (int) width)
		{
			if (__pixel(x, y, __get_color(sprite, (int) v.x, v.y)) == false)
				break ;
			v.x += v.w;
		}
		v.y += v.h;
	}
}

void	__image_pos(t_sprite *sprite, int x1, int y1)
{
	int		x;
	int		y;

	y = -1;
	while (++y < sprite->height)
	{
		x = -1;
		while (++x < sprite->width)
		{
			__pixel(x1 + x, y1 + y, \
			__get_color(sprite, x, y));
		}
	}
}

/*
void	__draw_line(t_vector begin, t_vector end, int color)
{
	int			pixels;
	t_vector	delta;

	delta.x = end.x - begin.x;
	delta.y = end.y - begin.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	delta.w = begin.x;
	delta.h = begin.y;
	while (pixels-- > 0)
	{
		(canva())->pixel(delta.w, delta.h, color);
		delta.w += delta.x;
		delta.h += delta.y;
	}
}
*/