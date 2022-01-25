/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:23:30 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:23:32 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		cur = (*lst)-> next;
		ft_lstdelone(*lst, del);
		(*lst) = cur;
	}
}
