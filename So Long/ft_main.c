/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:50:11 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/08 20:56:28 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_so_long.h"
#include "headers/ft_sprites.h"
#include "headers/ft_object.h"
#include <fcntl.h>

void	game_exit(void)
{
	t_object	*ob;
	t_object	*temp;

	engine()->is_load_full = 0;
	if (get_scene())
	{
		ob = get_scene()->objects;
		while (ob)
		{
			temp = ob;
			ob = ob->next;
			temp->destroy(temp);
		}
		ft_destroy_map(get_scene()->map);
	}
	free_ob((void **) &engine()->scene);
	ft_printf("\nmalloc_ob: %i |free_ob: %i\n", \
	engine()->malloc_ob, engine()->free_ob);
	if (engine()->ptr && engine()->win)
		mlx_destroy_window(engine()->ptr, engine()->win);
	system("leaks -- so_long");
	exit(-1);
}

static void	init_components(t_engine *e)
{
	t_scene		*scene;

	scene = new_scene();
	if (!e || !scene)
		return ;
	scene->x = 0;
	scene->y = 32;
	scene->map = new_map("images/map.xpm", 32, 32, scene);
	scene->add(scene, new_menu("images/icones.xpm", 32, 32), 0, -30);
	e->load(scene);
	init_events();
}

int	main(int argc, char **argv)
{
	static float	fps;

	if (argc <= 1)
	{
		perror("invalid argument");
		return (0);
	}
	engine()->malloc_ob = 0;
	engine()->free_ob = 0;
	init_engine(argv[1]);
	init_components(engine());
	mlx_loop_hook(engine()->ptr, engine_loop, &fps);
	mlx_loop(engine()->ptr);
}
