/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:46:30 by wmika             #+#    #+#             */
/*   Updated: 2022/01/25 13:48:29 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	error(char *str)
{
	ft_putstr_fd("Error \n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

char	*ft_strjoin_1(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new || !(s2))
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		free(s1);
	}
	if (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

void	cleanerit(char **extra)
{
	int	i;

	i = 0;
	while (extra[i])
	{
		free(extra[i]);
		i++;
	}
	free(extra);
}

int	check_empty_lines_1(char **str)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while ((*str)[j] != '\0')
	{
		if ((*str)[j] == '\n')
			count++;
		j++;
	}
	return (count);
}

void	check_empty_line(t_params *par, char **str)
{
	int		i;
	int		count;
	char	**extra;

	i = 0;
	if (!(*str))
		error("no map");
	extra = ft_split(*str, '\n');
	while (extra[i])
		i++;
	count = check_empty_lines_1(str);
	if (i == count + 1)
	{
		par -> map = extra;
		par -> height = i;
	}
	else
	{
		cleanerit(extra);
		error("empty lines");
	}
}
