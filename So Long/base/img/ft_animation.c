/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:57:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/04 21:42:21 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"
#include <fcntl.h>

static char	*get_path_animation(const char *pasta, const char *path, int size)
{
	int		i;
	int		p;
	char	*t;

	i = -1;
	p = 6;
	t = malloc_ob("path_animation", sizeof(char) * size + 4);
	while (pasta[++i])
		t[i] = pasta[i];
	t[i++] = '/';
	while (++p < (size - 4))
	{
		t[i++] = path[p];
	}
	t[i++] = '.';
	t[i++] = 'a';
	t[i++] = 'n';
	t[i] = 0;
	return (t);
}

static int	cread_aniation(t_object *ob, int i, char *buffer, int is_number)
{
	int			n;

	ob->animator.list[i].img = 0;
	ob->animator.list[i].is_repeat = 0;
	ob->animator.list[i].img_selct = 0;
	while (*buffer)
	{
		is_number = 0;
		n = strn_to_int(&buffer, 0, &is_number, \
		&ob->animator.list[i].is_repeat);
		if (is_number && n < ob->sprite.size)
		{
			if (!ob->animator.list[i].img)
				ob->animator.list[i].img = ob->sprite.imgs[n];
			else
				ob->animator.list[i].img_selct->next = ob->sprite.imgs[n];
			ob->animator.list[i].img_selct = ob->sprite.imgs[n];
			ob->animator.list[i].img_selct->next = 0;
		}
	}
	ob->animator.list[i].img_selct = ob->animator.list[i].img;
	return (1);
}

void	set_animation(t_object *ob, t_type_animation type)
{
	if (ob->animator.type != type)
	{
		ob->animator.animation = &ob->animator.list[type];
		ob->animator.animation->img_selct = ob->animator.animation->img;
		ob->animator.animation->time = 0;
		ob->animator.animation->time_max = 0;
	}
	ob->animator.is_animation = ob->animator.animation != 0;
}

void	stop_animation(t_object *ob)
{
	if (ob->animator.animation)
		ft_render_object(ob, ob->animator.animation->img);
	ob->animator.is_animation = 0;
}

int	load_animation(t_object *ob, char *path)
{
	int		fd;
	char	*buffer;
	int		index;

	index = -1;
	buffer = 0;
	path = get_path_animation("animation", path, ft_strlen(path));
	fd = open(path, O_RDONLY);
	while (fd >= 0 && get_next_line(fd, &buffer))
	{
		if (++index < MAX_ANIMATIONS && \
		cread_aniation(ob, index, buffer, 0) && buffer)
			free_ob((void **)&buffer);
	}
	ob->animator.animation = 0;
	ob->animator.type = NONE;
	set_animation(ob, STOPPED);
	close(fd);
	free_ob((void **) &path);
	return (ob != 0);
}
