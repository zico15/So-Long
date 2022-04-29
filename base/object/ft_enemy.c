/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:13:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/29 16:53:13 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static void	updade(struct s_object *ob)
{
	(void) ob;
	return ;
}

static void	collision(t_object *this, t_object *player)
{
	if (this && player && player->type == PLAYER)
	{
		player->updade = NULL;
		game_exit("Game Over\n");
	}
}

t_object	*new_enemy(char *path, int w, int h)
{
	t_object	*ob;

	ob = new_obj(path, w, h, ENEMY);
	ob->updade = updade;
	ob->collision = collision;
	ob->next = 0;
	return (ob);
}
