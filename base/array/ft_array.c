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

static t_element	*add_element(void *value)
{
	t_element	*e;

	if (!*this_array())
		return (NULL);
	e = malloc(sizeof(t_element));
	if (!e)
		return (NULL);
	e->value = value;
	e->next = NULL;
	if (!(*this_array())->begin)
		(*this_array())->begin = e;
	else
		(*this_array())->end->next = e;
	(*this_array())->end = e;
	(*this_array())->size++;
	return (e);
}

static void	*get_element(int index)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!*this_array())
		return (NULL);
	e = (*this_array())->begin;
	while (e)
	{
		if (i == index)
			return (e->value);
		e = e->next;
		i++;
	}
	return (0);
}

static t_element	*remove_element(t_element	*e)
{
	t_element	*b;
	t_element	*t;

	if (!*this_array() || !e)
		return (NULL);
	b = (*this_array())->begin;
	t = (*this_array())->begin;
	while (b)
	{
		if (b == e)
		{
			if (t == b)
				(*this_array())->begin = b->next;
			else
				t->next = b->next;
			free(b);
			(*this_array())->size--;
			if (!(*this_array())->size)
				(*this_array())->end = 0;
			return (e);
		}
		t = b;
		b = b->next;
	}
	return (e);
}

int	destroy(void)
{
	t_element	*b;
	t_element	*e;

	if (!*this_array())
		return (0);
	b = (*this_array())->begin;
	while (b && --(*this_array())->size)
	{
		e = b;
		b = b->next;
		if (e)
			free(e);
	}
	free(*this_array());
	*this_array() = NULL;
	return (1);
}

t_array	*new_array(void)
{
	t_array	*a;

	a = malloc(sizeof(t_array));
	if (a)
	{
		a->size = 0;
		a->begin = NULL;
		a->end = NULL;
		a->add = add_element;
		a->get = get_element;
		a->remove = remove_element;
		a->destroy = destroy;
		*this_array() = a;
	}
	return (a);
}
