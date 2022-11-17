/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/17 01:37:38 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <math.h>
# include <ft_string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <limits.h>
# include <sys/time.h>
# include <ft_this.h>
# include <ft_base_array.h>


# define BUFFER_SIZE 999999
# define PI 3.14159265
# define GRID_SIZE 32
# define GRID_MIN_SIZE 20
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97
# define KEY_M 109
# define KEY_E 101
# define KEY_ESC 65307
# define KEY_SPACE 32
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define EVENT_PRESS 0
# define EVENT_RELEASE 1
# define EVENT_CLICK 2
# define MOVE_LEN 0.08
# define ROTATION_LEN 0.01
# define VIEW_ANGLE 50
# define N_RAYS	W_WIDTH
# define COLOR_TRANSPARENT 0xd411aa
# define MINIMAP_FRAME 200


typedef struct s_engine
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;

} t_engine;

typedef struct s_vector
{
	double		x;
	double		y;
	double		w;
	double		h;
}	t_vector;



//			util
char		*get_next_line(int fd);
int			free_ob(void *v);
int			free_list(void **values);
void		*malloc_ob(size_t __size);

//			vector
t_vector	vector(double x, double y, double w, double h);
int			vector_distance(t_vector a, t_vector b);
t_vector	*new_vector(double x, double y);
t_vector	vector_zero(void);
t_vector	*copy_vector(t_vector *v);

t_engine	*engine();
t_engine 	*cread_engine(char *title);

#endif
