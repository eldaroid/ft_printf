/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:45:27 by fgracefo          #+#    #+#             */
/*   Updated: 2019/09/22 18:19:19 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	char	*ret;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	len = ft_strlen((char *)s);
	while (ft_isspace(s[len - 1]) && len > i)
		len--;
	ret = ft_strsub(s, i, len - i);
	return (ret);
}
