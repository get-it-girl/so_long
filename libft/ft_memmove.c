/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:24:19 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:24:20 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*c;
	const char	*new;
	char		*another_c;
	const char	*another_new;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (len != 0)
	{
		c = dst;
		new = src;
		if (c < new)
		{
			while (len--)
				*c++ = *new++;
		}
		else
		{
			another_c = c + (len - 1);
			another_new = new + (len - 1);
			while (len--)
				*another_c-- = *another_new--;
		}
	}
	return (dst);
}
