/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:50:11 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 18:37:59 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_so_long.h"
#include "headers/ft_sprites.h"
#include "headers/ft_object.h"
#include <fcntl.h>

void	game_exit(void)
{
	mlx_destroy_window(engine()->ptr, engine()->win);
	exit(-1);
}

static void	init_components(t_engine *e)
{
	t_scene		*scene;

	scene = new_scene();
	if (!e || !scene)
		return ;
	scene->player = new_player("images/player.xpm", 64, 64);
	e->load(scene);
	init_events();
}

int	main(void)
{
	static float	fps;

	instance_engine();
	init_components(engine());
	mlx_loop_hook(engine()->ptr, engine_loop, &fps);
	mlx_loop(engine()->ptr);
}
