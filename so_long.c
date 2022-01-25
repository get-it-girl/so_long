/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:24:44 by wmika             #+#    #+#             */
/*   Updated: 2022/01/25 13:49:34 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_params *par, char *placement, int x, int y)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(par->mlx, placement, &img_width, &img_height);
	mlx_put_image_to_window(par->mlx, par->wind, img, x, y);
}

int	render_const_frame(t_params *par)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < par -> height)
	{
		x = 0;
		while (x < par -> width)
		{
			if (par->map[y][x] == 'E')
				print_img(par, EXIT, x * 64, y * 64);
			else if (par -> map[y][x] == '1')
				print_img(par, WALLS, x * 64, y * 64);
			else
				print_img(par, GROUND, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}

void	count_moves(t_params *par)
{
	print_img(par, WALLS, 0, 0);
	ft_putnbr_fd(par->moves, 1);
	write(1, "\n", 1);
	mlx_string_put(par->mlx, par->wind, 30, 30, BLUE, ft_itoa(par->moves));
	par->moves++;
}

void	move_player(t_params *par, int x, int y)
{
	if (par->map[par->p_y + y][par->p_x + x] == '1')
		return ;
	if (par->map[par->p_y + y][par->p_x + x] == 'C')
	{
		par->map[par->p_y + y][par->p_x + x] = '0';
		print_img(par, GROUND, (par->p_x + x) * 64, (par->p_y + y) * 64);
		par->score++;
	}
	if (par->map[par->p_y + y][par->p_x + x] == 'E')
	{
		if (par->collect == par->score)
			par->won = 1;
		else
			return ;
	}
	count_moves(par);
	print_img(par, GROUND, par->p_x * 64, par->p_y * 64);
	par->p_x = par->p_x + x;
	par->p_y = par->p_y + y;
}

int	main(int argc, char *argv[])
{
	t_params	par;

	par.moves = 1;
	if (argc != 2)
		error("invalid args");
	check_map(&par, argv[1]);
	par.mlx = mlx_init();
	par.wind = mlx_new_window(par.mlx, par.width * 64,
			par.height * 64, "Game by wmika");
	hooks(&par);
	mlx_loop(par.mlx);
	return (0);
}
