/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:14:54 by fgracefo          #+#    #+#             */
/*   Updated: 2019/09/23 21:16:10 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
	}
	else if (s1)
		return (ft_strdup(s1));
	else if (s2)
		return (ft_strdup(s2));
	else
		return (NULL);
	if ((new = ft_strnew(len1 + len2)) && (s1 || s2))
	{
		len1 = 0;
		while (*s1)
			new[len1++] = *(s1++);
		while (*s2)
			new[len1++] = *(s2++);
		new[len1] = '\0';
	}
	return (new);
}
