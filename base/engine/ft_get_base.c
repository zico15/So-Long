/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:35:10 by edos-san          #+#    #+#             */
/*   Updated: 2022/04/25 23:07:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

struct s_scene	*get_scene(void)
{
	return (engine()->scene);
}

t_engine	*engine(void)
{
	static t_engine	e;

	return (&e);
}

int	strn_to_int(char **v, int n, int *is_number, int *is_repeat)
{
	if (v && *v && **v >= '0' && **v <= '9')
	{
		n = (n * 10) + (**v - '0');
		(*v)++;
		*is_number = 1;
		return (strn_to_int(v, n, is_number, is_repeat));
	}
	else
	{
		while (v && **v && !(**v >= '0' && **v <= '9'))
		{
			if (**v == 'R' && ++(*v) && (**v == ',' || **v == ';'))
				*is_repeat = 1;
			else
				++(*v);
		}
	}
	return (n);
}
