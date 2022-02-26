/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:13:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 17:44:33 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static int	input_key_up(int key, t_object *ob)
{
	if ((key == 13 || key == 1 || key == 0 || key == 2) && ob)
		ob->move(key, ob);
	return (1);
}

static int	input_key_down(int key, t_object *ob)
{
	if ((key == 13 || key == 1 || key == 0 || key == 2) && ob)
		ob->move(key, ob);
	return (1);
}

static void	updade(struct s_object *ob)
{
	(void) ob;
	return ;
}

t_object	*new_player(char *path, int w, int h)
{
	t_object	*ob;

	ob = new_obj(path, w, h);
	ob->updade = updade;
	mlx_hook(engine()->win, 2, 1, input_key_up, ob);
	mlx_hook(engine()->win, 3, 2L, input_key_down, ob);
	return (ob);
}
