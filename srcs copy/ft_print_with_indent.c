/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_indent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:28:13 by ashea             #+#    #+#             */
/*   Updated: 2020/07/07 16:13:04 by ashea            ###   ########.fr       */
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
		write(1, " ", 1);
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
