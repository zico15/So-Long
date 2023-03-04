/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 03:53:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object.h>

int game_exit()
{
	
	printf("exit\n");
	exit(0);
	return (0);
}

int	game_loop(void)
{
	if (engine()->is_key_press)
		(scene())->funct_key(engine()->keys, EVENT_PRESS);
	if (scene() && scene()->render)
		scene()->render(canva());
	mlx_put_image_to_window(engine()->mlx, engine()->win, \
	canva()->data.img, 0, 0);
	return (0);
}


typedef struct s_arg
{
	int x; 
	int y; 
	int i; 
	int j;
}	t_arg;


void	tes(t_arg t)
{
	printf("x: %i y: %i i: %i j: %i\n", t.x, t.y, t.i, t.j);
}

int	main(int argc, char **argv)
{
	t_engine	*e;


	(void) argv;
	if (argc < 2 || argc >= 50)
	return (printf("ERROR ARG!\n"));
	e = cread_engine("SO_LONG", 800, 800);
	init_canva();
	e->scene = new_scene();
	scene()->add(new_player());
	mlx_loop_hook(engine()->mlx, game_loop, NULL);
	// t_map *m = (t_map *) new_map();
	// m->load(argv[1]);
	mlx_hook(e->win, 17, 0, game_exit, NULL);
	return (mlx_loop(e->mlx));
}
