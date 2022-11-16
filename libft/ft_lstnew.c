/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:23:22 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/08 15:32:04 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*elem;

	elem = (t_list *) ft_calloc(1, sizeof(struct s_list));
	if (elem == 0)
		return (0);
	elem -> content = content;
	elem -> next = 0;
	return (elem);
}
