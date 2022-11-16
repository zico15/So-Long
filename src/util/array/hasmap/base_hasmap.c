/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:13:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/16 23:42:18 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_base_array.h>
#include <ft_string.h>

t_element		*__put_hasmap(char *key, void	*value);
t_element		*__get_index_hasmap(int index);
t_element		*__get_key_hasmap(char *key);
void			__remove_index_hasmap(int index);
void			__remove_element_hasmap(char	*key);
void			**__to_str_hashmpa(void);

void			__base_for_each(void (*fun)(t_element *e, void *v), void *o);
t_element		*__base_set_element(int index, void *value);
void			__base_remove_element_index(int index);
int				__base_free_element(void *value);
void			**__to_str(void);
void			__destroy_element(t_element	*e);
void			__base_remove_element_value(void *value);

void	**__to_str_hashmpa(void)
{
	t_element	*temp;
	void		**list;
	int			i;
	char		*str_temp;

	if (!fthis()->array)
		return (NULL);
	list = malloc_ob(sizeof(void *) * ((fthis()->array)->size + 1));
	if (!list)
		return (NULL);
	i = 0;
	temp = (fthis()->array)->begin;
	while (temp)
	{
		str_temp = string().join(temp->key, "=");
		list[i++] = string().join(str_temp, temp->value);
		free_ob(str_temp);
		temp = temp->next;
	}
	list[i] = NULL;
	return (list);
}

static int	base_destroy_hashmap(void)
{
	if (!fthis()->hashmap)
		return (0);
	if (fthis()->hashmap->list)
	{
		array(fthis()->hashmap->list)->destroy();
		fthis()->hashmap->list = NULL;
	}
	free_ob(fthis()->hashmap);
	fthis()->hashmap = NULL;
	return (1);
}

static int	base_size_hashmap(void)
{
	if (!fthis()->hashmap)
		return (0);
	return (array(fthis()->hashmap->list)->size);
}

t_hashmap	*hashmap(t_hashmap *a)
{
	if (a)
		fthis()->array = a->list;
	fthis()->hashmap = a;
	return (a);
}

void	*new_hashmap(void)
{
	t_hashmap	*a;

	a = malloc_ob(sizeof(t_hashmap));
	if (a)
	{
		a->list = new_array();
		a->put = __put_hasmap;
		a->get_index = __get_index_hasmap;
		a->get_key = __get_key_hasmap;
		a->remove_index = __remove_index_hasmap;
		a->remove_key = __remove_element_hasmap;
		a->destroy = base_destroy_hashmap;
		a->for_each = __base_for_each;
		a->size = base_size_hashmap;
		a->to_str = __to_str_hashmpa;
		hashmap(a);
	}
	return (a);
}
