/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 04:57:27 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/01 14:09:40 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"
/***
 * if ((x >= temp->x && (temp->x + temp->w) <= (x + ob->w)) \
			&& (temp->y >= y && (temp->y + temp->h) <= (y + ob->h)))
 * 
*/
t_object	*ft_collision(t_object *ob, int x, int y)
{
	t_object	*temp;

	temp = get_scene()->objects;
	while (temp)
	{
		if (temp != ob && temp->type != EMPTY)
		{
			if (x == temp->x && (y + ob->h / 2) == temp->y)
				return (temp);
		}
		temp = temp->next;
	}
	return (0);
}
