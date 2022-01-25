/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:24:46 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:24:47 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*new;
	int				i;

	i = 0;
	new = (unsigned char *)s;
	while (new[i] != '\0')
	{
		if (new[i] == (unsigned char)c)
			return ((char *)&new[i]);
		i++;
	}
	if (new[i] == (unsigned char)c)
		return ((char *)&new[i]);
	return ((void *) 0);
}
