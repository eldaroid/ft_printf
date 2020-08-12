/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:39:12 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/12 13:00:27 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_flags(t_flag flag, int	k)
{
	int		i;

	i = 0;
	if (flag.size.star > 0)
		i = flag.size.star;
	if (flag.size.zero > 0)
		i = flag.size.zero;
	if (flag.size.plus > 0)
		i = flag.size.plus;
	if (flag.size.space > 0)
		i = flag.size.space;
	i -= k;
	return (i);
}

int			ft_print_integer(va_list list, t_flag flag)
{
	long long int		i;
	char	*str;
	int		str_len;
	int		k;
	
	i = (flag.length.l != 'z' && flag.length.l != 'j') ? ft_length_int(list, flag) : va_arg(list, long long int);;
	str = ft_itoa_base(i, 10, flag);
	str_len = ft_strlen(str);
	if (flag.space > 0)
	{
		if (flag.size.space && flag.dot && flag.size.space > flag.size.dot)
			flag.size.star = flag.size.space * flag.length.minus;
		else if (!flag.plus && i >= 0)
			write(1, " ", 1);
	}
	else if (flag.zero && flag.dot && flag.size.zero > flag.size.dot)
		flag.size.star = flag.size.zero;
	if (flag.plus == 1 && !flag.star)
		flag.size.star = flag.size.plus;
	k = (flag.plus == 1) ? flag.size.star - 1: flag.size.star;
	while (k-- > str_len)
		write(1, " ", 1);
	if (flag.plus == 1 && i >= 0)
	{
		if (i >= 0)
			write(1, "+", 1);
		if (flag.star == 1)
			flag.size.star = (flag.size.star >= 0) ? flag.size.star++ : flag.size.star--;
			// flag.size.star++;
	}
	str_len = ft_print_with_indent(str, flag.size.star, str_len, 1);
	if (flag.plus || flag.space)
	{
		if ((flag.plus || flag.space) && (flag.size.star >= str_len || (-1) * flag.size.star >= str_len))
			str_len = (flag.size.star > 0) ? flag.size.star : (-1) * (flag.size.star);
		else if (i >= 0)
			str_len++;
	}
	if (flag.minus_plus == 2)
	{
		k = (flag.size.plus > flag.size.star) ? flag.size.plus : flag.size.star;
		while (k-- > str_len)
			write(1, " ", 1);
		str_len = (flag.size.plus > flag.size.star) ? flag.size.plus : flag.size.star;
	}
	return (str_len);
}