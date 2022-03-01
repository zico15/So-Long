/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:45:53 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/01 14:18:46 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

static char	*convert_base(char *str, int n, char *base, int size_base)
{
	if (n < -(size_base - 1) || n > (size_base - 1))
		str = convert_base(str, (n / size_base), base, size_base);
	*str++ = base[(n % size_base)];
	*str = 0;
	return (str);
}

static void	ft_render_menu(t_object *ob, void	*img)
{
	char	str[30];
	int		index;

	(void) img;
	index = 0;
	if (ob && ob->animator.list[0].is_repeat && ob->sprite.size > 250)
	{
		convert_base(str, engine()->steps, "0123456789", 10);
		mlx_put_image_to_window(engine()->ptr,
			engine()->win, ob->sprite.imgs[27], ob->x + 5, ob->y - 3);
		mlx_string_put(engine()->ptr,
			engine()->win, ob->x + 35, ob->y, 0x00FF0000, str);
		convert_base(str, engine()->collected, "0123456789", 10);
		index = ft_strlen(str);
		str[index++] = ' ';
		str[index++] = '\\';
		str[index++] = ' ';
		convert_base(&(str[index]), engine()->collectibles, "0123456789", 10);
		mlx_put_image_to_window(engine()->ptr,
			engine()->win, ob->sprite.imgs[250], ob->x + 67, ob->y - 5);
		mlx_string_put(engine()->ptr,
			engine()->win, ob->x + 99, ob->y, 0x00FF0000, str);
	}
}

t_object	*new_menu(char *path, int w, int h)
{
	t_object	*ob;

	ft_printf("menu: ");
	ob = new_obj(path, w, h, EMPTY);
	ob->render = ft_render_menu;
	ob->animator.animation = 0;
	ob->animator.list[0].is_repeat = 1;
	return (ob);
}
