/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:23:53 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:23:54 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		count;

	count = 1;
	cur = lst;
	if (cur == NULL)
		return (0);
	while (cur -> next != NULL)
	{
		cur = cur -> next;
		count++;
	}
	return (count);
}
