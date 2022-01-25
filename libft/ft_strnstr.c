/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:25:23 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:25:24 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *) s1);
	while (i <= len && s1[i] != '\0')
	{
		j = 0;
		new = (char *)&s1[i];
		if (s1[i] == s2[j])
		{
			while (s1[i] == s2[j] && s2[j] != '\0' && i < len && s1[i] != '\0')
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return (new);
			i = i - j;
		}
		i++;
	}
	return ((void *)0);
}
