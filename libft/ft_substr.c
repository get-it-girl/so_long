/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:25:40 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:25:41 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len >= ft_strlen(s + start))
		new = malloc (sizeof(char) * (ft_strlen(s + start) + 1));
	else
		new = malloc (sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		new[i] = s[start + i];
		i++;
	}
	new[len] = '\0';
	return (new);
}
