/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:25:36 by wmika             #+#    #+#             */
/*   Updated: 2022/01/25 13:56:42 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	etrim_extra(int *begin, int *i)
{
	*begin = 0;
	*i = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		begin;
	int		end;
	int		i;

	etrim_extra(&begin, &i);
	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[begin] != '\0' && check_set(s1[begin], set) == 1)
		begin++;
	while (end > begin && check_set(s1[end - 1], set))
		end--;
	new = malloc (sizeof(char) * (end - begin + 1));
	if (new == NULL)
		return (NULL);
	while (begin < end)
	{
		new[i] = s1[begin];
		i++;
		begin++;
	}
	free((char *)s1);
	new[i] = '\0';
	return (new);
}
