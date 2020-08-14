/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:39:12 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 14:59:55 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			size_flags(t_flag flag, int k)
{
	int				i;

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

int			ft_printint(char *str, int size_star, int str_len, t_flag flag)
{
	int					count;
	int					clean;

	clean = 1;
	count = check_count(str_len, size_star);
	while (size_star-- > str_len)
		if (clean == 1)
			clean = 1;
	write(1, str, str_len);
	if (size_star < 0 && flag.length.minus == -1)
	{
		count = 0;
		while ((-1) * (size_star++) > str_len + 1)
		{
			write(1, " ", 1);
			count++;
		}
		if (flag.plus == 1 && flag.minus_plus != 2 && str[0] != '-')
			count++;
		count += str_len;
	}
	ft_free(clean, str);
	return (count);
}

int			check_flag_size(t_flag flag, long long int i, int str_len)
{
	int					k;

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
	k = (flag.plus == 1 && i > 0) ? flag.size.star - 1 : flag.size.star;
	while (k-- > str_len)
		write(1, " ", 1);
	if (flag.plus == 1 && i >= 0)
	{
		if (i >= 0)
			write(1, "+", 1);
		if (flag.star == 1 && flag.length.minus == -1)
			flag.size.star++;
	}
	return (flag.size.star);
}

int			check_strlen(t_flag flag, char *str, int str_len, long long int i)
{
	if (flag.length.minus == -1)
		str_len = ft_printint(str, flag.size.star, str_len, flag);
	else
		str_len = ft_print_with_indent(str, flag.size.star, str_len, 1);
	if ((flag.plus || flag.space) &&
		!(flag.length.minus == -1 && flag.plus == 1))
	{
		if ((flag.plus || flag.space) &&
			(flag.size.star >= str_len || (-1) * flag.size.star >= str_len))
			str_len = (flag.size.star > 0) ? flag.size.star
				: (-1) * (flag.size.star);
		else if (i >= 0)
			str_len++;
	}
	return (str_len);
}

int			ft_print_integer(va_list list, t_flag flag)
{
	long long int		i;
	char				*str;
	int					str_len;
	int					k;

	i = (flag.length.l != 'z' && flag.length.l != 'j') ? ft_lenint(list, flag)
			: va_arg(list, long long int);
	str = ft_itoa_base(i, 10, flag);
	str_len = ft_strlen(str);
	flag.size.star = check_flag_size(flag, i, str_len);
	k = 0;
	str_len = check_strlen(flag, str, str_len, i);
	if (flag.minus_plus == 2)
	{
		k = (flag.size.plus > flag.size.star) ? flag.size.plus : flag.size.star;
		if (i < 0)
			k++;
		while (--k > str_len)
			write(1, " ", 1);
		str_len = (flag.size.plus > flag.size.star) ? flag.size.plus
			: flag.size.star;
	}
	return (str_len);
}
