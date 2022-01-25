/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:25:21 by wmika             #+#    #+#             */
/*   Updated: 2022/01/25 13:44:31 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"

# define BUFFER_SIZE 1 

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

# define KEYPRESS 2
# define KEYEXIT 17

# define WALLS "./assets/wall.xpm"
# define GROUND "./assets/ground.xpm"
# define TREAT "./assets/treat.xpm"
# define PLAYER "./assets/player.xpm"
# define EXIT "./assets/exit.xpm"

# define BLUE 0x0040FF

typedef struct s_params{
	char	**map;
	size_t	width;
	size_t	height;
	void	*mlx;
	void	*wind;
	size_t	p_x;
	size_t	p_y;
	int		collect;
	int		score;
	int		moves;
	int		won;

}		t_params;

char	*ft_strjoin_1(char *s1, char *s2);
void	read_map(char *map_file, char **str);
void	check_map(t_params *par, char *map_file);
void	check_empty_line(t_params *par, char **str);
void	cleanerit(char **extra);
void	check_name(char *map_file);
void	check_walls(t_params *par);
void	check_walls_line(char **extra, t_params *par);
void	check_line(char **s, t_params *par);
void	error(char *str);
void	print_img(t_params *par, char *placement, int x, int y);
int		render_const_frame(t_params *par);
void	set_values(t_params *par);
void	move_player(t_params *par, int x, int y);
int		press_key(int keycode, t_params *par);
void	hooks(t_params *par);
int		render_next_frame(t_params *par);
int		gameover(t_params *par);
void	count_moves(t_params *par);
void	check_line_2(char c, int **doub);
int		check_empty_lines_1(char **str);

#endif
