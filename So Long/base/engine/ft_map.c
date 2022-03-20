/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:44:08 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/05 16:53:53 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"
#include "./../../headers/ft_array.h"

static int	cheack_line(t_array	*list, int size_line, char empty)
{
	int		x_i;
	char	*end;
	char	*start;

	x_i = -1;
	start = list->get(list, 0);
	end = list->get(list, size_line);
	while (start && end && ++x_i < size_line)
	{
		if (start[x_i] != empty || end[x_i] != empty)
		{
			list = list->destroy(&list);
			perror("erro map:");
			game_exit();
		}
	}
	engine()->width = engine()->scale * (size_line + 1);
	engine()->height = engine()->scale * list->size;
	return ((size_line > 0));
}

static int	cheack_coluna(char *str, char empty, int size_line)
{
	size_line -= 2;
	if (size_line <= 0 || str[0] != empty || str[size_line] != empty)
		return (0);
	return (1);
}

void	instance_object(t_title_map *map, int x, int y, t_scene *scene)
{
	int	i;

	i = engine()->list->get(engine()->list, y)[x];
	map->map[x][y] = map->this->animator.list[(i == '1')].img;
	x *= engine()->scale;
	y *= engine()->scale;
	if (i == '1')
		scene->add(scene, new_obj(0, 32, 32, WALL), x, y);
	else if (i == 'C')
	{
		scene->add(scene, new_obj("images/coins.xpm", 32, 32, 2), x, y);
	}
	else if (i == 'P')
		scene->add(scene, new_player("images/bardo64_1_.xpm", 32, 64), x, y);
}

int	load_file_map(int fd)
{
	int		size;
	char	*str;

	str = 0;
	engine()->list = new_array();
	ft_printf("load_file_map\n");
	get_next_line(fd, &str);
	size = ft_strlen(str);
	while (str && *str)
	{
		if (engine()->list->add(engine()->list, str))
		{
			if (size != (int) ft_strlen(str) || !cheack_coluna(str, '1', size))
			{
				engine()->list = engine()->list->destroy(&engine()->list);
				perror("erro map: ");
				game_exit();
			}
		}
		get_next_line(fd, &str);
	}
	return (cheack_line(engine()->list, size - 2, '1'));
}
