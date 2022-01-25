/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:24:06 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:24:06 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*n1;
	const unsigned char	*n2;
	size_t				i;

	i = 0;
	n1 = s1;
	n2 = s2;
	while (i < n)
	{
		if (n1[i] == n2[i])
			i++;
		else
			return (n1[i] - n2[i]);
	}
	return (0);
}
