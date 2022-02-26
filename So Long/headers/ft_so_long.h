/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:47:13 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 17:46:32 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_array.h"
# include "ft_printf.h"
# include "ft_sprites.h"
# include "ft_object.h"

# define __NULL__	0
# define _TIME_FTP_ 30
# define _SIZE_BLOCK_ 64

typedef enum e_type
{
	SCENE,
	ENGINE
}	t_type;

typedef struct s_scene
{
	int					id;
	void				*background;
	struct s_title_map	*map;
	t_object			*objects;
	t_object			*player;
	int					(*load)(struct s_scene *scene);
	int					(*unload)(struct s_scene *scene);
	int					(*updade)(int fps);
}	t_scene;

typedef struct s_engine
{
	int				fps;
	int				width;
	int				height;
	int				is_load_full;
	char			scale;
	void			*ptr;
	void			*win;
	int				(*load)(struct s_scene *scene);
	int				(*clean)(struct s_scene *scene);
	struct s_scene	*scene;
}	t_engine;

//				render
void			ft_render_map(void);
void			ft_render_object(t_object *ob, void	*img);
void			ft_render_animation(t_object *ob);

//				scene
struct s_scene	*get_scene(void);
struct s_scene	*new_scene(void);
void			init_events(void);
void			game_exit(void);

//				image
void			load_sprites(t_object *ob, char *path, int size_w, int size_h);
void			*cread_img(char *path, int width, int height);
int				load_animation(t_object *ob, char *path);
void			set_animation(t_object *ob, t_type_animation type);
void			stop_animation(t_object *ob);

//				file
char			*get_next_line(int fd);
int				file_write(int fd, char *line, int is_free);
int				file_clean(char *paths);

//				engine
int				engine_loop(float	*fps);
int				engine_render(float fps);
int				engine_updade(float fps);
void			instance_engine(void);
t_engine		*engine(void);
int				strn_to_int(char **v, int n, int *is_number, int *is_repeat);
#endif