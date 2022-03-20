/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:17:08 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/18 17:10:08 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static int	ft_updade_scene(int fps)
{
	t_object	*ob;

	ob = get_scene()->objects;
	ft_render_map();
	while (ob)
	{
		if (ob->sprite.size)
			ft_render_animation(ob);
		ob = ob->next;
	}
	return (fps);
}

static int	ft_load_scene(t_scene *scene)
{
	ft_render_map();
	return (!scene);
}

static int	ft_add_object(t_scene *scene, t_object *ob, int x, int y)
{
	t_object	*n;

	n = scene->objects;
	if (!ob)
		return (0);
	if (ob)
	{
		ob->x = scene->x + x;
		ob->y = scene->y + y;
	}
	ob->next = 0;
	while (n)
	{
		if (!n->next)
		{
			ob->next = 0;
			n->next = ob;
			return (1);
		}
		n = n->next;
	}
	scene->objects = ob;
	return (0);
}

static int	ft_remove_ob(t_object *ob)
{
	t_object	*ob_next;
	t_object	*ob_last;

	ob_last = 0;
	ob_next = get_scene()->objects;
	while (ob && ob_next)
	{
		if (ob_next == ob)
		{
			if (ob_last)
				ob_last->next = ob->next;
			else
				get_scene()->objects = ob->next;
			ob->destroy(ob);
			ob = 0;
			return (1);
		}
		ob_last = ob_next;
		ob_next = ob_next->next;
	}
	return (0);
}

struct s_scene	*new_scene(void)
{
	t_scene	*scene;

	scene = malloc_ob("new_scene", sizeof(t_scene) * 1);
	if (!scene)
	{
		perror("new_scene->");
		return (0);
	}
	scene->objects = 0;
	scene->background = 0;
	scene->map = 0;
	scene->remove = ft_remove_ob;
	scene->add = ft_add_object;
	scene->updade = ft_updade_scene;
	scene->load = ft_load_scene;
	scene->unload = 0;
	scene->background = mlx_new_image(engine()->ptr,
			engine()->width, engine()->height);
	return (scene);
}
