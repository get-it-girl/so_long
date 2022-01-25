/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:49:24 by wmika             #+#    #+#             */
/*   Updated: 2022/01/25 13:49:50 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int keycode, t_params *par)
{
	if (par->won == 1 || keycode == ESC)
		gameover(par);
	if (keycode == A)
		move_player(par, -1, 0);
	if (keycode == S)
		move_player(par, 0, 1);
	if (keycode == D)
		move_player(par, 1, 0);
	if (keycode == W)
		move_player(par, 0, -1);
	return (0);
}

int	gameover(t_params *par)
{
	size_t	i;

	i = 0;
	if (par->won == 1)
		ft_putstr_fd(">>>>>>>>>>>>>>>>>> YOU WON <<<<<<<<<<<<<<<\n", 1);
	while (i < par->height)
	{
		free(par->map[i]);
		i++;
	}
	free(par->map);
	free(par->mlx);
	free(par->wind);
	sleep(1);
	exit(0);
}

int	render_next_frame(t_params *par)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < par->height)
	{
		x = 0;
		while (x < par->width)
		{
			if (par->map[y][x] == 'C')
			{
				print_img(par, GROUND, x * 64, y * 64);
				print_img(par, TREAT, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	print_img(par, PLAYER, par->p_x * 64, par->p_y * 64);
	return (0);
}

void	hooks(t_params *par)
{
	mlx_hook(par->wind, KEYPRESS, 1L << 0, press_key, par);
	mlx_hook(par->wind, KEYEXIT, 1L << 0, gameover, par);
	render_const_frame(par);
	mlx_loop_hook(par->mlx, render_next_frame, par);
}
