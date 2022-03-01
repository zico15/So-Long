/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:50:55 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/01 14:13:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"
#include <fcntl.h>

static int	ft_load_scene(t_scene *scene)
{
	engine()->is_load_full = 0;
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
	engine()->sleep++;
	engine_updade(*fps);
	engine_render(*fps);
	*fps = 0;
	return (*fps);
}

void	instance_engine(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror(path);
		game_exit();
	}
	(void) path;
	engine()->fps = 0;
	engine()->is_load_full = 0;
	engine()->load = ft_load_scene;
	engine()->scale = 32;
	engine()->clean = 0;
	engine()->sleep = 0;
	engine()->steps = 0;
	engine()->collected = 0;
	engine()->collectibles = 0;
	load_file_map(fd);
	close(fd);
	engine()->ptr = mlx_init();
	(engine()->win) = mlx_new_window(engine()->ptr,
			engine()->width, engine()->height + 32, "SO LONG");
	engine()->scene = 0;
	ft_printf("instance engine\n");
}
