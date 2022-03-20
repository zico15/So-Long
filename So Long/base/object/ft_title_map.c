/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_title_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:31:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/19 20:59:42 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"
#include "./../../headers/ft_array.h"

void	ft_destroy_map(t_title_map *map)
{
	int			i;

	if (map)
	{
		i = -1;
		if (map->this)
		{
			while (map->this->sprite.imgs && ++i < map->this->sprite.size)
				mlx_destroy_image(engine()->ptr, map->this->sprite.imgs[i]);
			free_ob((void **) &map->this->sprite.imgs);
		}
		i = -1;
		while (++i < map->this->w)
			free_ob((void **)&map->map[i]);
		map->this->destroy(map->this);
		free_ob((void **) &*map->map);
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
	map = malloc_ob("erro map: ", sizeof(t_title_map));
	map->this = new_obj(path, w, h, EMPTY);
	map->this->w = engine()->width / engine()->scale;
	map->this->h = engine()->height / engine()->scale;
	map->map = malloc_ob("erro map: ", sizeof(void *) * map->this->w);
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
