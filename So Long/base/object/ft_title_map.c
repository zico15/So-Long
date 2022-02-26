/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_title_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:31:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 16:23:28 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

struct s_title_map	*new_map(char *path, int w, int h)
{
	t_title_map	*map;
	int			index_w;
	int			index_h;

	index_w = -1;
	index_h = -1;
	map = (malloc(sizeof(t_title_map) * 1));
	if (!map)
		game_exit();
	map->this = new_obj(path, w, h);
	map->map = malloc(sizeof(void **) * w);
	while (++index_w < w)
	{
		map->map[index_w] = malloc(sizeof(void *) * h);
		index_h = -1;
		while (++index_h < h)
			map->map[index_w][index_h] = map->this->sprite.imgs[10];
	}
	return (map);
}
