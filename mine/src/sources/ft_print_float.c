/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:42:07 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 16:47:54 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int				new_flag_star(t_flag flag, long double number,
				long long str_len)
{
	long long int	k;

	if (flag.space > 0)
	{
		if (flag.size.space && flag.dot && flag.size.space > flag.size.dot)
			flag.size.star = flag.size.space;
		else if (!flag.plus && !is_double_negative(number))
			write(1, " ", 1);
	}
	else if (flag.zero && flag.dot && flag.size.zero > flag.size.dot)
		flag.size.star = flag.size.zero;
	if (flag.plus == 1 && !flag.star)
		flag.size.star = flag.size.plus;
	k = (flag.plus == 1) ? flag.size.star - 1 : flag.size.star;
	while (k-- > str_len)
		write(1, " ", 1);
	if (flag.plus == 1 && !is_double_negative(number))
	{
		if (!is_double_negative(number))
			write(1, "+", 1);
		if (flag.star == 1)
			flag.size.star++;
	}
	return (flag.size.star);
}

long long int	check_my_strlen(t_flag flag, long double number,
				long long str_len, char *str)
{
	long long int	k;

	str_len = ft_print_with_indent(str, flag.size.star, str_len, 1);
	if (flag.plus || flag.space)
	{
		if ((flag.plus || flag.space) &&
			(flag.size.star >= str_len || (-1) * flag.size.star >= str_len))
			str_len = (flag.size.star > 0) ? flag.size.star
				: (-1) * (flag.size.star);
		else if (!is_double_negative(number))
			str_len++;
	}
	if (flag.minus_plus == 2)
	{
		k = (flag.size.plus > flag.size.star) ? flag.size.plus : flag.size.star;
		while (k-- > str_len)
			write(1, " ", 1);
		str_len = (flag.size.plus > flag.size.star) ? flag.size.plus
				: flag.size.star;
	}
	return (str_len);
}

int				ft_print_float(va_list list, t_flag flag)
{
	long double		number;
	char			*str;
	long long int	str_len;

	number = (long double)(flag.length.lll == 1) ? va_arg(list, long double)
			: va_arg(list, double);
	if (flag.length.lll != 1)
		str = ft_string_float(number, flag);
	else
		str = ft_long_float(number, flag);
	str_len = ft_strlen(str);
	flag.size.star = new_flag_star(flag, number, str_len);
	return (check_my_strlen(flag, number, str_len, str));
}
