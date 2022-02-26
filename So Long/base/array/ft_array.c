/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:51:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/20 13:51:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_array.h"

static t_element	*add_element(struct s_array *a, char *value)
{
	t_element	*e;

	e = malloc(sizeof(e) * ((a != 0) - (a == 0)));
	if (!e)
		return (0);
	e->value = value;
	e->next = 0;
	a->size++;
	if (!a->begin)
	{
		a->begin = e;
		a->end = e;
	}
	else
	{
		a->end->next = e;
		a->end = e;
	}
	return (e);
}

static void	*get_element(struct s_array *a, int index)
{
	int			i;
	t_element	*e;

	i = 0;
	e = a->begin;
	while (e)
	{
		if (i == index)
			return (e->value);
		e = e->next;
		i++;
	}
	return (0);
}

static t_element	*remove_element(struct s_array *a, t_element	*e)
{
	t_element	*b;
	t_element	*t;

	if (!a || !e)
		return (0);
	b = a->begin;
	t = a->begin;
	while (b)
	{
		if (b == e)
		{
			if (t == b)
				a->begin = b->next;
			else
				t->next = b->next;
			free(b);
			a->size--;
			if (!a->size)
				a->end = 0;
			return (e);
		}
		t = b;
		b = b->next;
	}
	return (e);
}

static t_array	*destroy(struct s_array **a)
{
	t_element	*b;
	t_element	*e;
	int			i;

	i = (*a)->size;
	if (!(*a))
		return (0);
	b = (*a)->begin;
	while (--i)
	{
		e = b;
		b = b->next;
		if (e)
			free(e);
	}
	free((*a));
	(*a) = NULL;
	return (0);
}

struct s_array	*new_array(void)
{
	t_array	*a;

	a = malloc(sizeof(a) * 1);
	if (a)
	{
		a->size = 0;
		a->begin = 0;
		a->end = 0;
		a->add = add_element;
		a->get = get_element;
		a->remove = remove_element;
		a->destroy = destroy;
	}
	return (a);
}
