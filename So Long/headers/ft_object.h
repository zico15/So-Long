/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:08:58 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 15:44:38 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
# define FT_OBJECT_H

# include "ft_so_long.h"

typedef struct s_size
{
	int				width;
	int				height;
}	t_size;

typedef struct s_object
{
	struct s_sprites	sprite;
	struct s_animator	animator;
	int					x;
	int					y;
	int					w;
	int					h;
	void				(*move)(int d, struct s_object *ob);
	void				(*updade)(struct s_object *ob);
	void				(*destroy)(struct s_object *ob);
}	t_object;

typedef struct s_title_map
{
	struct s_object	*this;
	void			***map;
}	t_title_map;

t_size				object_size(int w, int h);
t_object			*new_obj(char *path, int w, int h);
void				ft_render_object(t_object *ob, void	*img);
t_object			*new_player(char *path, int w, int h);
struct s_title_map	*new_map(char *path, int w, int h);

#endif
