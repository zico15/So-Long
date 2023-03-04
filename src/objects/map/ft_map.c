/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:45:14 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 00:13:15 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_object_util.h>


static int	_load(char *path)
{
	void	*file;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	file = new_array();
	array(file)->is_value_destroy = 0;
	while (array(file)->add(get_next_line(fd)))
		;
	close(fd);
	map()->map = (char **) array(file)->to_str();
	this()->vector.h = array(file)->size;
	array(file)->destroy();
	printf("laod: %s size_h: %i\n", path, (int) this()->vector.h);
	return (1);
}

t_map	*map(void)
{
	return ((t_map *) this());
}

t_object	*new_map(void)
{
	t_map	*m;

	m = new_object_instance(sizeof(t_map));
	m->load = _load;
	return ((t_object *) m);
}