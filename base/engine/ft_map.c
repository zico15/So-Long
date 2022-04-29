/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:44:08 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/29 14:51:28 by edos-san         ###   ########.fr       */
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
	start = list->get(0);
	end = list->get(list->size - 1);
	while (start && end && ++x_i < size_line)
	{
		if (start[x_i] != empty || end[x_i] != empty)
			game_exit("Error Map");
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

int	check_obs(char i, int is_exit)
{
	static int	obs_type[10];

	if (i == 'P' && obs_type[PLAYER]++ >= 0)
		return (1);
	if (i == 'E' && obs_type[EXIT]++ >= 0)
		return (1);
	if (i == 'C' && obs_type[COLLECTIBLE]++ >= 0)
		return (1);
	if (is_exit && (obs_type[PLAYER] > 1 || obs_type[PLAYER] < 1))
		game_exit("Error: Number min/max player\n");
	if (is_exit && (obs_type[EXIT] > 1 || obs_type[EXIT] < 1))
		game_exit("Error: Number min/max exit\n");
	if (is_exit && obs_type[COLLECTIBLE] < 1)
		game_exit("Error: Number min collectible\n");
	if (i && (i != '0' && i != '1' && i != 'I'))
		game_exit("Error: invalid map\n");
	return (1);
}

void	instance_object(t_title_map *map, int x, int y, t_scene *scene)
{
	char	i;
	char	*str;

	(void) scene;
	str = (engine()->list)->get(y);
	i = str[x];
	map->map[x][y] = map->this->animator.list[(i == '1')].img;
	x *= engine()->scale;
	y *= engine()->scale;
	if (i == '1')
		scene->add(scene, new_obj(0, 32, 32, WALL), x, y);
	else if (i == 'C')
	{
		scene->add(scene, new_obj("images/collectable.xpm", 32, 32, 2), x, y);
	}
	else if (i == 'P')
		scene->add(scene, new_player("images/player.xpm", 32, 64), x, y);
	else if (i == 'I')
		scene->add(scene, new_enemy("images/enemy.xpm", 32, 32), x, y);
	else if (i == 'E')
		scene->add(scene, new_exit("images/exit.xpm", 32, 64), x, y);
	check_obs(i, 0);
}

int	load_file_map(int fd)
{
	int		size;
	char	*str;

	str = 0;
	engine()->list = new_array();
	get_next_line(fd, &str);
	if (!str)
		game_exit("Error: Load file map\n");
	size = ft_strlen(str);
	while (str && *str)
	{
		if (engine()->list->add(str))
		{
			if (size != (int) ft_strlen(str) || !cheack_coluna(str, '1', size))
				game_exit("Error: Load file map\n");
		}
		get_next_line(fd, &str);
	}
	return (cheack_line(engine()->list, size - 2, '1'));
}
