/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:42:54 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 15:53:17 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_indent(char *str, int size_star, int str_len, int clean)
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

int			ft_print_percent(t_flag flag)
{
	int		count;
	int		k;
	int		len;

	count = 0;
	while (flag.size.zero > 1)
	{
		flag.size.zero--;
		count++;
		write(1, "0", 1);
	}
	k = flag.size.star;
	len = 1;
	while (k-- > len)
		write(1, " ", 1);
	return (ft_print_indent("%", flag.size.star, 1, 0) + count);
}
