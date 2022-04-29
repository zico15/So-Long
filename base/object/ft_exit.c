/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:13:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/29 14:58:30 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static void	updade(struct s_object *ob)
{
	(void) ob;
	if (!ob->render && engine()->collected == engine()->collectibles)
	{
		ob->animator.animation->time_max = 100;
		set_animation(ob, STOPPED);
		ob->render = ft_render_object_64;
	}
	if (ob->action)
	{
		if (ob->action > 5)
			game_exit("End Game!\n");
		ob->action++;
	}
	return ;
}

static void	collision(t_object *this, t_object *player)
{
	if (this && this->render && player && player->type == PLAYER)
	{
		this->action = 1;
		player->updade = NULL;
		set_animation(this, 8);
	}
}

t_object	*new_exit(char *path, int w, int h)
{
	t_object	*ob;

	ob = new_obj(path, w, h, EXIT);
	ob->updade = updade;
	ob->render = NULL;
	ob->collision = collision;
	ob->next = 0;
	return (ob);
}
