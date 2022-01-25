/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:25:17 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:25:18 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*si;
	unsigned char	*sa;

	i = 0;
	si = (unsigned char *)s1;
	sa = (unsigned char *)s2;
	while (i < n && sa[i] != '\0' && si[i] != '\0')
	{
		if (si[i] == sa[i])
			i++;
		else
			return (si[i] - sa[i]);
	}
	if (i == n)
		return (0);
	return (si[i] - sa[i]);
}
