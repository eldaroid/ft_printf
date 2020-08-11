/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:00:43 by fgracefo          #+#    #+#             */
/*   Updated: 2019/09/14 18:20:36 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t l)
{
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	len = 0;
	while (s2[len])
		len++;
	i = 0;
	while (s1[i] && i < l)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j] && (i + j) < l)
			j++;
		if (len == j)
			return ((char*)&s1[i]);
		i++;
	}
	return (0);
}
