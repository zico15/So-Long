/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:44:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/17 00:33:14 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	vector_distance(t_vector a, t_vector b)
{
	int		x;
	int		y;

	x = a.x - b.x;
	if (x < 0)
		x *= -1;
	y = a.y - b.y;
	if (y < 0)
		y *= -1;
	return (x + y);
}

t_vector	*new_vector(double x, double y)
{
	t_vector	*tmp;

	tmp = malloc_ob(sizeof(t_vector));
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}
