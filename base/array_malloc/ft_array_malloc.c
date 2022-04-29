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

#include "./../../headers/ft_array_malloc.h"

static t_element	*add_element(void *value)
{
	t_element	*e;

	if (!this())
		return (NULL);
	e = malloc(sizeof(t_element));
	if (!e)
		return (NULL);
	e->value = value;
	e->next = NULL;
	if (!(this())->begin)
		(this())->begin = e;
	else
		(this())->end->next = e;
	(this())->end = e;
	return (e);
}

static void	*get_element(int index)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!(this()))
		return (NULL);
	e = (this())->begin;
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

	if (!this() || !e)
		return (NULL);
	b = this()->begin;
	t = this()->begin;
	while (b)
	{
		if (b == e)
		{
			if (t == b)
				(this())->begin = b->next;
			else
				t->next = b->next;
			free(b);
			((this()))->size--;
			if (!(this())->size)
				(this())->end = 0;
			return (e);
		}
		t = b;
		b = b->next;
	}
	return (e);
}

static int	ft_destroy(void)
{
	t_element	*b;
	t_element	*e;

	if (!this())
		return (0);
	b = (this())->begin;
	while (b && --(this())->size)
	{
		e = b;
		b = b->next;
		if (e)
		{
			if (e->value)
				free(e->value);
			free(e);
		}
		engine()->free_ob++;
	}
	(this())->begin = NULL;
	(this())->end = NULL;
	return (1);
}

t_array	*new_array_malloc(void)
{
	t_array	*a;

	a = this();
	if (a)
	{
		a->size = 0;
		a->begin = NULL;
		a->end = NULL;
		a->add = add_element;
		a->get = get_element;
		a->remove = remove_element;
		a->destroy = ft_destroy;
	}
	else
		game_exit("Error Malloc\n");
	return (a);
}
