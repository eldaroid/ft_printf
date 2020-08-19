/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:57:46 by fgracefo          #+#    #+#             */
/*   Updated: 2019/09/23 15:58:56 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t		flag;
	size_t		i;
	size_t		count;

	count = 1;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && flag == 1)
			flag = 0;
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

static int	count_letter(char const *s, int i, char c)
{
	int		count;

	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

static int	ft_free(char **new)
{
	int		i;

	i = -1;
	if (!(new))
		return (0);
	while (new[++i] != 0)
		free(new[i]);
	return (0);
}

static int	change_new(char **new, char const *s, char c)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	i = 0;
	while (s[i])
	{
		count = 0;
		if (s[i] != c)
		{
			count = count_letter(s, i, c);
			if (!(new[j] = (char *)ft_memalloc(sizeof(char) * count + 1)))
				return (ft_free(new));
			i += count - 1;
			j++;
		}
		i++;
	}
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		j;
	int		x;

	j = -1;
	x = -1;
	if (!s || !(new = (char **)ft_memalloc(sizeof(char *) * count_words(s, c))))
		return (NULL);
	if (!(change_new(new, s, c)))
		return (0);
	while (*s != '\0')
	{
		if (*s != c)
			++j;
		while (*s != c && *s != '\0')
		{
			new[j][++x] = *s;
			s++;
		}
		if (*s == '\0')
			return (new);
		x = -1;
		s++;
	}
	return (new);
}
