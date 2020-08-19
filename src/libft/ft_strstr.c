/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:32:34 by fgracefo          #+#    #+#             */
/*   Updated: 2019/09/14 18:18:00 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
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
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j])
			j++;
		if (len == j)
			return ((char*)&s1[i]);
		i++;
	}
	return (0);
}
