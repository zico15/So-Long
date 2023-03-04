/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:12:20 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 04:02:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_object_util.h>
#include <ft_util.h>

static void	__render_player(t_buffer *b)
{
	b->image_sub(this()->animation.sprite, this()->vector.x, this()->vector.y, \
	vector(45 * this()->animation.index, 0, 45, 110));
}

static void	__funct_key_player(char *key, int event)
{
	if (key['a'] && event == EVENT_CLICK)
		printf("EVENT_CLICK: %i\n", this()->animation.index++);
}


t_object	*new_player(void)
{
	t_player	*p;

	p = new_object_instance(sizeof(t_player));
	p->funct_key = __funct_key_player;
	p->render = __render_player;
	p->animation.sprite = canva()->load("imgs/pngfind.com-ryu.xpm");
	return ((t_object *) p);
}
