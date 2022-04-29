/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:50:11 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/29 20:12:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_so_long.h"
#include "headers/ft_sprites.h"
#include "headers/ft_object.h"
#include <fcntl.h>

void	game_exit(char	*msg)
{
	t_object	*ob;
	t_object	*temp;

	if (engine()->list)
		engine()->list->destroy();
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
	this()->destroy();
	ft_printf("\n%s\nmalloc_ob: %i | free_ob: %i\n\n", msg, \
	engine()->malloc_ob, engine()->free_ob);
	if (engine()->ptr && engine()->win)
		mlx_destroy_window(engine()->ptr, engine()->win);
	exit(0);
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

int	check_path(char *path)
{
	int				size;

	size = ft_strlen(path);
	if (size < 5)
		return (0);
	if (path[--size] == 'r' && path[--size] == 'e' && \
	path[--size] == 'b' && path[--size] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	static float	fps;
	t_array			*mallocs;

	if (argc <= 1 || !check_path(argv[1]))
	{
		perror("invalid argument");
		return (0);
	}
	engine()->list = NULL;
	mallocs = new_array_malloc();
	engine()->malloc_ob = 0;
	engine()->free_ob = 0;
	init_engine(argv[1]);
	init_components(engine());
	mlx_loop_hook(engine()->ptr, engine_loop, &fps);
	mlx_loop(engine()->ptr);
}
