/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/17 01:08:41 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int game_exit()
{
	
	printf("exit\n");
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_engine *e;

	(void) argv;
	if (argc < 2 || argc >= 50)
		return (printf("ERROR ARG!\n"));
	e = cread_engine("cub3D");
	mlx_hook(e->win, 17, 0, game_exit, NULL);
	return (mlx_loop(e->mlx));
}
