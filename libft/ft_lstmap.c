/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:23:21 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/08 15:31:58 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_elem;

	if (!(f || del))
		return (NULL);
	head = 0;
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst -> content));
		if (!(new_elem))
		{
			if (head == 0)
				head = new_elem;
			ft_lstclear(&head, del);
		}
		if (head != 0)
			ft_lstadd_back(&head, new_elem);
		else
			head = new_elem;
		lst = lst -> next;
	}
	return (head);
}
