/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:08:19 by ezequeil          #+#    #+#             */
/*   Updated: 2023/03/04 03:00:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_object.h>

int	funct_key_engine(char *key, int event)
{
	if (scene()->funct_key)
		(scene())->funct_key(key, event);
	return (0);
}

// int	__funct_mousse_engine(int keycode, void *vars)
// {
// 	int	x;
// 	int	y;

// 	(void) vars;
// 	engine()->is_mouse_press = keycode;
// 	mlx_mouse_get_pos(engine()->mlx, engine()->win, &x, &y);
// 	if (scene())
// 		(scene()->funct_mouse)(x, y, keycode);
// 	return (0);
// }

int	__funct_key_press(int key, void *o)
{
	(void) o;
	engine()->keys[key] = 1;
	engine()->is_key_press++;
	funct_key_engine(engine()->keys, EVENT_CLICK);
	return (0);
}

int	__funct_key_release(int key, void *o)
{
	(void) o;
	engine()->is_key_press--;
	engine()->keys[key] = 0;
	funct_key_engine(engine()->keys, EVENT_RELEASE);
	return (0);
}
