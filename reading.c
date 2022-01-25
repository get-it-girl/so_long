/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:24:55 by wmika             #+#    #+#             */
/*   Updated: 2022/01/25 13:48:05 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	read_map(char *map_file, char **str)
{
	char	*buff;
	int		fd;
	int		red;
	int		count;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	fd = open(map_file, O_RDONLY);
	*str = NULL;
	count = 0;
	if (fd == -1)
		error("error to open");
	red = read(fd, buff, BUFFER_SIZE);
	if (red == -1)
		error("Can't read map");
	while (red > 0)
	{
		*str = ft_strjoin_1(*str, buff);
		red = read(fd, buff, BUFFER_SIZE);
	}
	*str = ft_strtrim(*str, "\n");
	free (buff);
}

void	check_name(char *map_file)
{
	int	size;

	size = ft_strlen(map_file);
	if (ft_strncmp(&map_file[size - 4], ".ber\0", 5))
		error("incorrect name");
}

void	check_line_2(char c, int **doub)
{
	if (c != '1' && c != '0' && c != 'C'
		&& c != 'E' && c != 'P')
		error("extra characters");
	if (c == 'E')
		(*doub)[0]++;
	if (c == 'P')
		(*doub)[1]++;
	if (c == 'C')
		(*doub)[2]++;
}

void	check_line(char **s, t_params *par)
{
	size_t	i;
	int		*doub;
	size_t	j;

	doub = ft_calloc (3, sizeof(int));
	if (!doub)
		error("error calloc");
	i = 1;
	while (s[i] && i != par -> height - 1)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			check_line_2(s[i][j], &doub);
			j++;
		}
		i++;
	}
	if (doub[0] < 1 || doub[1] != 1 || doub[2] < 1)
		error("error with characters");
	free(doub);
}

void	check_walls_line(char **extra, t_params *par)
{
	size_t	i;

	i = 1;
	while (extra[i] && i != par -> height - 1)
	{
		if (extra[i][0] != '1' || extra[i][par -> width - 1] != '1')
			error("walls are not '1'");
		i++;
	}
}
