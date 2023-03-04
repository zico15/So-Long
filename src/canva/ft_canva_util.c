/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canva_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:35 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 02:43:07 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_canva.h>

bool	__pixel(int x, int y, int color);
int		__get_color(t_sprite *sprite, int x, int y);

void	__image(t_sprite *sprite, int x, int y)
{
	y = -1;
	while (++y < sprite->height)
	{
		x = -1;
		while (++x < sprite->width)
		{
			if (__pixel(x, y, __get_color(sprite, x, y)) == false)
				break ;
		}
	}
}

void	__image_sub(t_sprite *sprite, int x1, int y1, t_vector v1)
{
	int	x;
	int	y;

	y = -1;
	while (++y < v1.h)
	{
		x = -1;
		while (++x < v1.w)
		{
			if (__pixel(x + x1, y + y1, \
			__get_color(sprite, (v1.x + x), (v1.y + y))) == false)
				break ;
		}
	}
}
