/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:10:46 by eldaroid          #+#    #+#             */
/*   Updated: 2019/09/22 17:29:55 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*func;

	if (!lst)
		return (NULL);
	new = f(lst);
	func = new;
	while (lst->next)
	{
		lst = lst->next;
		func->next = f(lst);
		if (!(func->next))
		{
			free(func->next);
			return (NULL);
		}
		func = func->next;
	}
	return (new);
}
