/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:46:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/01 14:05:16 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static void	ft_move(int d, t_object *ob)
{
	if (ob)
	{
		ft_render_map_position(ob);
		if (d == 1)
		{
			set_animation(ob, WALKING_S);
			ob->set_position(ob, 0, ((d == 1) - (d == 13)) * engine()->scale);
		}
		else if (d == 13)
		{
			set_animation(ob, WALKING_W);
			ob->set_position(ob, 0, ((d == 1) - (d == 13)) * engine()->scale);
		}
		else if (d == 0)
		{
			set_animation(ob, WALKING_A);
			ob->set_position(ob, ((d == 2) - (d == 0)) * engine()->scale, 0);
		}
		else if (d == 2)
		{
			set_animation(ob, WALKING_D);
			ob->set_position(ob, ((d == 2) - (d == 0)) * engine()->scale, 0);
		}
		ft_render_map_position(ob);
	}
}

static void	ft_set_position(t_object *ob, int x, int y)
{
	ob->x += x;
	ob->y += y;
}

static void	ft_destroy(t_object *ob)
{
	int	i;

	i = -1;
	if (ob)
	{
		while (ob->sprite.imgs && ++i < ob->sprite.size)
			mlx_destroy_image(engine()->ptr, ob->sprite.imgs[i]);
		free_ob((void **) &ob->sprite.imgs);
		free_ob((void **) &ob);
		printf("destroy: ->object\n");
	}
}

static void	updade(struct s_object *ob)
{
	(void) ob;
	return ;
}

t_object	*new_obj(char *path, int w, int h, t_type_object type)
{
	t_object	*ob;

	ob = malloc_ob("new_obj", sizeof(t_object));
	ft_printf("new object-> %s\n", path);
	ob->sprite.imgs = 0;
	ob->animator.is_animation = 0;
	ob->animator.animation = 0;
	ob->animator.type = NONE;
	ob->render = ft_render_object;
	ob->set_position = ft_set_position;
	engine()->collectibles += (type == COLLECTIBLE);
	ob->type = type;
	ob->x = 0;
	ob->y = 0;
	ob->w = w;
	ob->h = h;
	ob->updade = updade;
	ob->move = ft_move;
	ob->destroy = ft_destroy;
	ob->next = 0;
	if (!path)
		return (ob);
	load_sprites(ob, path, w, h);
	load_animation(ob, path);
	return (ob);
}
