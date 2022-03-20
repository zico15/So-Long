/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:02:45 by edos-san          #+#    #+#             */
/*   Updated: 2022/03/04 20:52:42 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"
#include <fcntl.h>

typedef struct s_line
{
	char			*line;
	long			size_line;
	long			index;
	long			size_buffer;
	long			size_read;
	struct s_line	*v;
}	t_line;

static char
	*get_line(char *line, char *buffer, long size_buffer, long *size_line)
{
	t_line	data;

	data.size_line = -1;
	data.index = -1;
	data.size_buffer = -1;
	data.line = line;
	*size_line += size_buffer;
	line = malloc_ob("get_line", *size_line + 1 * sizeof(char));
	if (line)
	{
		line[*size_line] = 0;
		while (data.line && data.line[++data.size_line])
			line[++data.index] = data.line[data.size_line];
		data.size_line = -1;
		while (buffer && buffer[++data.size_line])
		{
			if (data.size_line < size_buffer)
				line[++data.index] = buffer[data.size_line];
			else
				buffer[++data.size_buffer] = buffer[data.size_line];
			buffer[data.size_line] = 0;
		}
	}
	free_ob((void **)&data.line);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	f[1000 + 1];
	t_line		d;

	*line = NULL;
	d.size_buffer = 0;
	d.index = 1;
	d.size_line = 0;
	while (fd >= 0 && f[d.size_buffer])
		d.size_buffer++;
	while (fd >= 0 && d.index > 0)
	{
		if (!f[0] || !d.size_buffer)
			d.size_buffer = read(fd, f, 1000);
		d.index = d.size_buffer;
		if (d.size_buffer > 0)
		{
			d.size_buffer = 0;
			while (f[d.size_buffer] && f[d.size_buffer] != '\n')
				d.size_buffer++;
			d.index = (d.index == d.size_buffer);
			d.size_buffer += f[d.size_buffer] == '\n';
			*line = get_line(*line, f, d.size_buffer, &d.size_line);
		}
	}
	return (d.size_line);
}

int	file_clean(char *paths)
{
	int	fd_write;

	fd_write = open(paths, O_TRUNC | O_WRONLY);
	if (fd_write == -1)
		return (0);
	write(fd_write, 0, 0);
	return (!close(fd_write));
}

int	file_write(int fd, char *line, int is_free)
{
	int		size;

	size = 0;
	if (fd == -1 || !line)
		return (0);
	while (line[size])
		size++;
	write (fd, line, size);
	if (is_free && line)
		free_ob((void **)&line);
	return (1);
}
