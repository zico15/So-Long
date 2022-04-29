/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:34:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/29 16:34:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

t_array	*this(void)
{
	static t_array	select;

	return (&select);
}

void	*malloc_ob(const char *erro, int size)
{
	void	*v;

	v = malloc(size);
	(void) size;
	(void) erro;
	if (!v)
		game_exit("Error Malloc\n");
	(this())->add(v);
	engine()->malloc_ob++;
	return (v);
}
