/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:43:14 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/12 17:44:13 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, char c, int n)
{
	unsigned char *a;

	a = (unsigned char *)s;
	if (n > 0)
	{
		while (n-- > 0)
			*(a++) = c;
	}
	return ;
}
