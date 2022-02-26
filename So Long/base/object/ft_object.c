/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:46:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 18:32:46 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static void	ft_move(int d, t_object *ob)
{
	if (ob)
	{
		ft_render_map();
		if (d == 1)
		{
			set_animation(ob, WALKING_S);
			ob->y += ((d == 1) - (d == 13)) * engine()->scale;
		}
		else if (d == 13)
		{
			set_animation(ob, WALKING_W);
			ob->y += ((d == 1) - (d == 13)) * engine()->scale;
		}
		else if (d == 0)
		{
			set_animation(ob, WALKING_A);
			ob->x += ((d == 2) - (d == 0)) * engine()->scale;
		}
		else if (d == 2)
		{
			set_animation(ob, WALKING_D);
			ob->x += ((d == 2) - (d == 0)) * engine()->scale;
		}
		ft_render_animation(ob);
	}
}

static void	ft_destroy(t_object *ob)
{
	if (ob)
	{
		mlx_destroy_image(engine()->ptr, ob->sprite.imgs[0]);
		ft_render_map();
		free(ob);
		printf("destroy\n");
	}
}

static void	updade(struct s_object *ob)
{
	(void) ob;
	return ;
}

t_object	*new_obj(char *path, int w, int h)
{
	t_object	*ob;

	ob = (malloc(sizeof(t_object) * 1));
	if (!ob)
		game_exit();
	ob->sprite.imgs = 0;
	ob->x = 0;
	ob->y = 64;
	ob->w = w;
	ob->h = h;
	ob->updade = updade;
	ob->move = ft_move;
	ob->destroy = ft_destroy;
	ft_printf("new object-> %s\n", path);
	load_sprites(ob, path, w, h);
	load_animation(ob, path);
	return (ob);
}
