/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:22:28 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:22:32 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*check_space(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	return (str);
}

static int	ft_putnbr(char *out)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (out[i] != '\0')
	{
		res = res * 10;
		res = res + (out[i] - '0');
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	char	*s1;
	char	out[20];
	int		i;
	int		j;

	i = 0;
	j = 0;
	s1 = check_space((char *)str);
	if (s1[0] == '-' || s1[0] == '+')
		i++;
	while (s1[i] >= '0' && s1[i] <= '9' && s1[i] != '\0' && j < 19)
	{
		out[j++] = s1[i++];
	}
	out[j] = '\0';
	if (ft_strlen(out) > 11 && s1[0] == '-')
		return (0);
	if (ft_strlen(out) > 11)
		return (-1);
	if (ft_strncmp(out, "-2147483648", 11) == 0)
		return (-2147483648);
	if (s1[0] == '-')
		return (ft_putnbr(out) * (-1));
	return (ft_putnbr(out));
}
