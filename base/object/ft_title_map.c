/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_title_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:31:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/25 22:22:07 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"
#include "./../../headers/ft_array.h"

t_array	**this_array(void)
{
	static t_array	*select;

	return (&select);
}

void	ft_destroy_map(t_title_map *map)
{
	int			i;

	if (map)
	{
		i = -1;
		if (map->this)
		{
			while (0 && map->this->sprite.imgs && ++i < map->this->sprite.size)
				mlx_destroy_image(engine()->ptr, map->this->sprite.imgs[i]);
		}
		i = -1;
		map->this->destroy(map->this);
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
	engine()->list->destroy();
	engine()->list = NULL;
	check_obs(0, 1);
	return (map);
}
