/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:08:41 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 15:53:00 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hashing(char type, char **str)
{
	(*str)[0] = '0';
	(*str)[1] = type;
}

char		*ft_hash(int power, t_flag flag)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (power + 1))))
		return (NULL);
	str[power] = '\0';
	if (flag.hash && (flag.type == 'x' || flag.type == 'X'))
		hashing(flag.type, &str);
	else if (flag.hash && flag.type == 'o')
	{
		str[power + 2] = '\0';
		str[0] = '0';
	}
	return (str);
}
