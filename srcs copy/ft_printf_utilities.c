/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:35:01 by ashea             #+#    #+#             */
/*   Updated: 2020/07/07 16:17:26 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				ft_strlen(const char *s)
{
	size_t			len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char				*ft_strchr(const char *str, int c)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char*)(str) + i);
	return (NULL);
}

int					ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}

int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	size_t			i;

	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	i = 0;
	while (s1_copy[i] == s2_copy[i] && s1_copy[i])
		i++;
	return (s1_copy[i] - s2_copy[i]);
}

char				*ft_strdup(const char *src)
{
	size_t			i;
	char			*src2;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
		i++;
	src2 = (char*)malloc((i + 1) * sizeof(char));
	if (!src2)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}
