/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:48:09 by fgracefo          #+#    #+#             */
/*   Updated: 2019/09/23 15:59:08 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((new = (char *)malloc(sizeof(char) * len + 1)) && s)
	{
		while (*(s + start) && len-- > 0)
		{
			new[i] = *(s + start);
			start++;
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
