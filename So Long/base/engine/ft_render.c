/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:46:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 18:41:14 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

void	ft_render_object(t_object *ob, void	*img)
{
	//ft_render_map();
	if (ob && img)
		mlx_put_image_to_window(engine()->ptr,
			engine()->win, img, ob->x, ob->y);
}

void	ft_render_map(void)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	if (get_scene()->map != 0)
	{
		while (++x < get_scene()->map->this->w)
		{
			y = -1;
			while (++y < get_scene()->map->this->h)
				mlx_put_image_to_window(engine()->ptr, engine()->win,
					get_scene()->map->map[x][y], (x * 64), (y * 64));
		}
	}
	/*if (get_scene()->background)
		mlx_put_image_to_window(engine()->ptr, engine()->win,
			get_scene()->background, 0, 0);*/
}

void	ft_render_animation(t_object *ob)
{
	if (!ob)
		return ;
	ob->animator.time += 0.01;
	if (ob->animator.time < ob->animator.time_max)
		return ;
	ob->animator.time = 0;
	if (ob->animator.animation && ob->animator.is_animation)
	{
		ob->animator.animation->img_selct = ob->animator
			.animation->img_selct->next;
		if (!ob->animator.animation->img_selct)
		{
			ob->animator.animation->img_selct = ob->animator.animation->img;
			ob->animator.is_animation = ob->animator.animation->is_repeat;
		}
		ft_render_object(ob, ob->animator.animation->img_selct);
	}
	else if (ob->animator.animation)
		ft_render_object(ob, ob->animator.animation->img_selct);
}
