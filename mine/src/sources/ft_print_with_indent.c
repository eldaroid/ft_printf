/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_indent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:40:29 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/12 14:18:54 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_with_indent(char *str, int size_star, int str_len, int clean)
{
	int	count;

	count = str_len;
	if (size_star > str_len || (-1) * size_star > str_len)
		count = (size_star > 0) ? size_star : (-1) * size_star;
	while (size_star-- > str_len)
		if (clean == 1)
				clean = 1;
	write(1, str, str_len);
	if (size_star < 0)
		while ((-1) * (size_star++) > str_len + 1)
			write(1, " ", 1);
	if (clean)
	{
		free(str);
		str = NULL;
	}
	return (count);
}