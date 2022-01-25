/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:23:18 by wmika             #+#    #+#             */
/*   Updated: 2022/01/23 14:23:18 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*longo;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	longo = (*lst);
	while (longo -> next)
		longo = longo -> next;
	longo -> next = new;
}
