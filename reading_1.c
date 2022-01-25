/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:24:55 by wmika             #+#    #+#             */
/*   Updated: 2022/01/25 13:48:18 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_walls(t_params *par)
{
	char	**extra;
	int		i;

	i = 1;
	extra = par -> map;
	par -> width = ft_strlen(extra[0]);
	while (extra[i])
	{
		if (par -> width != ft_strlen(extra[i]))
			error("not rectangular map");
		i++;
	}
	i = 0;
	while (extra[0][i] != '\0' && extra[par -> height - 1][i] != '\0')
	{
		if (extra[0][i] != '1' || extra[par -> height - 1][i] != '1')
			error("first or/and last line isn't walls");
		i++;
	}
	check_line(extra, par);
	check_walls_line(extra, par);
}

void	set_values(t_params *par)
{
	size_t	x;
	size_t	y;

	par->collect = 0;
	par->score = 0;
	par->won = 0;
	y = 0;
	while (y < par->height)
	{
		x = 0;
		while (x < par->width)
		{
			if (par->map[y][x] == 'P')
			{
				par->p_y = y;
				par->p_x = x;
			}
			if (par->map[y][x] == 'C')
				par->collect++;
			x++;
		}
		y++;
	}
}

void	check_map(t_params *par, char *map_file)
{
	char	*str;

	check_name(map_file);
	read_map(map_file, &str);
	(void) par;
	check_empty_line(par, &str);
	free(str);
	check_walls(par);
	set_values(par);
}
