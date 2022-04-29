/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:46:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/29 14:58:01 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

void	ft_render_object(t_object *ob, void	*img)
{
	if (ob)
	{
		mlx_put_image_to_window(engine()->ptr,
			engine()->win, img, (ob->x), ob->y);
	}
}

void	ft_render_object_64(t_object *ob, void	*img)
{
	if (ob)
	{
		mlx_put_image_to_window(engine()->ptr,
			engine()->win, img, (ob->x), ob->y - 32);
	}
}

void	ft_render_map(void)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	mlx_put_image_to_window(engine()->ptr, engine()->win,
		get_scene()->background, 0, 0);
	if (get_scene()->map != 0)
	{
		while (++x < get_scene()->map->this->w)
		{
			y = -1;
			while (++y < get_scene()->map->this->h)
				if (get_scene()->map->map[x][y])
					mlx_put_image_to_window(engine()->ptr, engine()->win,
						get_scene()->map->map[x][y],
						(get_scene()->x + x * engine()->scale),
						(get_scene()->y + y * engine()->scale));
		}
	}
}

void	ft_render_map_position(t_object *ob)
{
	int	x;
	int	y;

	x = ob->x / engine()->scale;
	y = ob->y / engine()->scale;
	if (0 && get_scene()->map)
		mlx_put_image_to_window(engine()->ptr, engine()->win,
			get_scene()->map->map[x][y],
			x * engine()->scale, y * engine()->scale);
}

void	ft_render_animation(t_object *ob)
{
	if (!ob->render)
		return ;
	if (ob->animator.animation && ob->animator.is_animation)
	{
		ob->animator.animation->time += 0.01;
		if (ob->animator.animation->time < ob->animator.animation->time_max)
			return ;
		ob->animator.animation->time = 0;
		if (ob->animator.animation->img_selct)
			ob->animator.animation->img_selct = ob->animator
				.animation->img_selct->next;
		if (!ob->animator.animation->img_selct)
		{
			ob->animator.animation->img_selct = ob->animator.animation->img;
			ob->animator.is_animation = ob->animator.animation->is_repeat;
		}
		ob->render(ob, ob->animator.animation->img_selct);
	}
	else if (ob->animator.animation)
		ob->render(ob, ob->animator.animation->img_selct);
	else
		ob->render(ob, ob->animator.list[STOPPED].img);
}
