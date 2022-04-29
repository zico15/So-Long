/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:13:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/29 14:58:49 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static int	input_key_up(int key, t_object *ob)
{
	if (!ob->updade)
		return (0);
	if (!engine()->is_load_full)
		return (0);
	if ((key == 13 || key == 1 || key == 0 || key == 2) && ob)
		ob->move(key, ob);
	engine()->sleep = 0;
	return (1);
}

static int	input_key_down(int key, t_object *ob)
{
	if (!ob->updade)
		return (0);
	if (!engine()->is_load_full)
		return (0);
	if ((key == 13 || key == 1 || key == 0 || key == 2) && ob)
		ob->move(key, ob);
	engine()->sleep = 0;
	return (1);
}

static void	updade(struct s_object *ob)
{
	if (engine()->sleep == 50)
	{
		if (ob->animator.type != ATTACK_C)
			ft_printf("engine()->player->sleep\n");
		set_animation(ob, ATTACK_C);
		engine()->sleep = 0;
	}
	return ;
}

static void	ft_set_position(t_object *ob, int x, int y)
{
	t_object	*collision;

	collision = ft_collision(ob, ob->x + x, ob->y + y);
	if (!collision || (collision && (collision->type == EMPTY || \
	collision->type == COLLECTIBLE)))
	{
		if (collision && collision->type == COLLECTIBLE)
			engine()->collected += get_scene()->remove(collision);
		ob->x += x;
		ob->y += y;
		engine()->steps++;
	}
	else if (collision && collision->collision)
		collision->collision(collision, ob);
}

t_object	*new_player(char *path, int w, int h)
{
	t_object	*ob;

	ob = new_obj(path, w, h, PLAYER);
	ob->updade = updade;
	ob->render = ft_render_object_64;
	ob->set_position = ft_set_position;
	ob->next = 0;
	mlx_hook(engine()->win, 2, 1, input_key_up, ob);
	mlx_hook(engine()->win, 3, 2L, input_key_down, ob);
	return (ob);
}
