/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:19:45 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/25 20:15:05 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"
#include "./../../headers/ft_sprites.h"

static void	set_pixel(char	*des, char	*or)
{
	des[0] = or[0];
	des[1] = or[1];
	des[2] = or[2];
	des[3] = or[3];
}

void	cread_sprites(t_image *o, t_image *c, int i, t_object *ob)
{
	o->x_o = 0;
	o->y_o = 0;
	while (ob->sprite.imgs && ++i < ob->sprite.size)
	{
		o->y = -1;
		ob->sprite.imgs[i] = mlx_new_image(engine()->ptr, o->size_w, o->size_h);
		c->pixels = mlx_get_data_addr(ob->sprite.imgs[i],
				&c->bits, &c->size, &c->endian);
		while (++o->y < o->size_h)
		{
			o->x = -1;
			while (++o->x < o->size_w)
				set_pixel(&c->pixels[o->x * 4 + c->size * o->y], &o->\
				pixels[(o->x + (o->x_o * o->size_w)) * 4 + o->size * (o->y + \
				(o->y_o * o->size_h))]);
		}
		o->x_o++;
		if ((o->x_o * o->size_w) >= o->width)
		{
			o->x_o = 0;
			o->y_o++;
		}
	}
}

void	load_sprites(t_object *ob, char *path, int size_w, int size_h)
{
	t_image		o;
	t_image		c;
	t_mlx_img	*img;

	ob->sprite.index = 0;
	ob->sprite.size = 0;
	if (!path)
	{
		perror(path);
		return ;
	}
	o.img = mlx_xpm_file_to_image(engine()->ptr, path, &o.width, &o.height);
	if (!o.img)
	{
		perror(path);
		return ;
	}
	img = o.img;
	ob->sprite.index = 0;
	ob->sprite.size = (o.width / size_w) * (o.height / size_h);
	ob->sprite.imgs = malloc_ob("sprites", ob->sprite.size * sizeof(void *));
	o.pixels = mlx_get_data_addr(o.img, &o.bits, &o.size, &o.endian);
	o.size_w = size_w;
	o.size_h = size_h;
	cread_sprites(&o, &c, -1, ob);
}
