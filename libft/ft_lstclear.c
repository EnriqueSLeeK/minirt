/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:23:18 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/08 15:30:14 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*aux;

	if (lst && *lst && del)
	{
		curr = *lst;
		while (curr)
		{
			aux = curr;
			curr = curr -> next;
			ft_lstdelone(aux, del);
		}
		*lst = curr;
	}
}
