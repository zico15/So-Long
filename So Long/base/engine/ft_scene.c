/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:17:08 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 18:38:26 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static int	ft_unload_scene(t_scene *scene)
{
	ft_printf("unload scene\n");
	return (!scene);
}

static int	ft_updade_scene(int fps)
{
	ft_render_map();
	ft_render_animation(get_scene()->player);
	return (fps);
}

static int	ft_load_scene(t_scene *scene)
{
	ft_updade_scene(0);
	return (!scene);
}

struct s_scene	*new_scene(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene) * 1);
	if (!scene)
	{
		perror("new_scene->");
		return (0);
	}
	scene->objects = 0;
	scene->player = 0;
	scene->background = 0;
	scene->map = 0;
	scene->updade = ft_updade_scene;
	scene->load = ft_load_scene;
	scene->unload = ft_unload_scene;
	scene->background = mlx_new_image(engine()->ptr,
			engine()->width, engine()->height);
	ft_printf("new scene\n");
	return (scene);
}
