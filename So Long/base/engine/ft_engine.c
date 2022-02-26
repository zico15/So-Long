/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:50:55 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 13:57:59 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static int	ft_load_scene(t_scene *scene)
{
	engine()->is_load_full = 0;
	if (get_scene())
		get_scene()->unload(get_scene());
	engine()->scene = scene;
	scene->load(scene);
	engine()->is_load_full = (engine()->scene != 0);
	return ((scene != 0));
}

int	engine_updade(float fps)
{
	get_scene()->updade(fps);
	return (fps);
}

int	engine_render(float fps)
{
	return (fps);
}

int	engine_loop(float	*fps)
{
	if (!engine()->is_load_full)
		return (0);
	*fps += 0.01;
	if (*fps < _TIME_FTP_)
		return (0);
	*fps = 0;
	engine_updade(*fps);
	engine_render(*fps);
	return (*fps);
}

void	instance_engine(void)
{
	engine()->fps = 0;
	engine()->is_load_full = 0;
	engine()->load = ft_load_scene;
	engine()->width = 500;
	engine()->height = 500;
	engine()->scale = 32;
	engine()->ptr = mlx_init();
	(engine()->win) = mlx_new_window(engine()->ptr,
			engine()->width, engine()->height, "SO LONG");
	engine()->scene = 0;
}
