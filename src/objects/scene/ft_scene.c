/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:12:20 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 03:58:11 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_object_util.h>
#include <ft_util.h>

static void	render_scene(t_buffer *b)
{
	t_element	*item;

	item = array(scene()->event_render)->begin;
	while (item)
	{
		fthis()->object = ((t_object *) item->value);
		fthis()->object->render(b);
		item = item->next;
	}
}

static void	__funct_key(char *key, int type_event)
{
	t_element	*item;

	item = array(scene()->event_keys)->begin;
	while (item)
	{
		fthis()->object = ((t_object *) item->value);
		(fthis()->object)->funct_key(key, type_event);
		item = item->next;
	}
}

static void	__add_object(t_object *ob)
{
	if (ob == NULL)
		return ;
	array(scene()->objects)->add(ob);
	if (ob->funct_key)
		array(scene()->event_keys)->add(ob);
	if (ob->render)
		array(scene()->event_render)->add(ob);
}

t_scene	*new_scene(void)
{
	t_scene	*s;

	s = new_object_instance(sizeof(t_scene));
	s->render = render_scene;
	s->funct_key = __funct_key;
	s->objects = new_array();
	s->event_keys = new_array();
	s->event_render = new_array();
	s->event_update = new_array();
	s->add = __add_object;
	return (s);
}
