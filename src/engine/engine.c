/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:03:44 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 02:58:14 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	__funct_key_press(int key, void *o);
int	__funct_key_release(int key, void *o);

t_engine	*engine(void)
{
	static t_engine	e;

	return (&e);
}

t_scene	*scene(void)
{
	return (engine()->scene);
}

t_engine	*cread_engine(char *title, int width, int height)
{
	engine()->width = width;
	engine()->height = height;
	engine()->mlx = mlx_init();
	(engine()->win) = mlx_new_window(engine()->mlx, width, height, title);
	mlx_hook(engine()->win, 2, (1L << 0), __funct_key_press, NULL);
	mlx_hook(engine()->win, 3, (1L << 1), __funct_key_release, NULL);
	return (engine());
}
