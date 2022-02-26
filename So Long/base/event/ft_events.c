/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:58:24 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/26 14:51:39 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../headers/ft_so_long.h"

int	ft_keys(int key, void *v)
{
	if (key == 53 && !v)
		game_exit();
	return (0);
}

void	init_events(void)
{
	mlx_hook(engine()->win, 3, 1L << 0, ft_keys, 0);
}
