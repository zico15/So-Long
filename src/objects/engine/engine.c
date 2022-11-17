/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:03:44 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/17 00:08:01 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_engine	*engine()
{
    static  t_engine	e;

    return (&e);
}

t_engine *cread_engine(char *title)
{
    engine()->mlx = mlx_init();
	engine()->win = mlx_new_window(engine()->mlx, 800, 800, title);
    return (engine());
}