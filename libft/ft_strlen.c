/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:25:11 by wmika             #+#    #+#             */
/*   Updated: 2022/01/24 12:25:52 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		i++;
	}
	return (i);
}
