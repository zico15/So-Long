/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_title_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:31:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/01 12:53:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"
#include "./../../headers/ft_array.h"

void	ft_destroy_map(t_title_map *map)
{
	int			i;
	t_size		size;

	i = -1;
	size.width = engine()->width / engine()->scale - 1;
	size.height = engine()->height / engine()->scale - 1;
	if (map)
	{
		map->this->destroy(map->this);
		while (size.width)
		{
			free_ob(map->map[size.width]);
			size.width--;
		}
		free_ob((void **) *map->map);
		free_ob((void **) &map);
	}
}

struct s_title_map	*new_map(char *path, int w, int h, t_scene *scene)
{
	t_title_map	*map;
	int			x;
	int			y;
	int			i;

	x = -1;
	y = -1;
	map = malloc_ob("erro map: ", sizeof(t_title_map) * 1);
	ft_printf("map: ", path);
	map->this = new_obj(path, w, h, EMPTY);
	map->this->w = engine()->width / engine()->scale;
	map->this->h = engine()->height / engine()->scale;
	map->map = malloc_ob("erro map: ", sizeof(void **) * map->this->w);
	i = 0;
	while (++x < map->this->w)
	{
		map->map[x] = malloc_ob("map: ", sizeof(void *) * map->this->h);
		y = -1;
		while (++y < map->this->h)
			instance_object(map, x, y, scene);
	}
	engine()->list = engine()->list->destroy(&engine()->list);
	return (map);
}
