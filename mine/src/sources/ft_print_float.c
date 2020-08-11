/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:42:07 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/09 18:35:28 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	*reverse_array(char *str)
// {
// 	char	tmp;
// 	char	tmp1;
// 	int		i;
// 	int		str_len;

// 	str_len = ft_strlen(str);
// 	i = 0;
// 	if (str[i])
// 		tmp = str[i];
// 	i++;
// 	while (str_len / 2 != 0)
// 	{
// 		tmp1 = str[str_len - 1];
// 		str[str_len - 1] = tmp;
// 		str[i - 1] = tmp1;
// 		i++; 
// 		str_len--;
// 	}
// 	return (str);	
// }

int		ft_print_float(va_list list,t_flag flag)
{
	double	number;
	char	*str;
	long long	str_len;
	int			k;
	
	number = va_arg(list, double);

	str = ft_string_float(number,flag);
	str_len = ft_strlen(str);
	// write(1, str, str_len);

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
	k = (flag.plus == 1) ? flag.size.star - 1: flag.size.star;
	while (k-- > str_len)
		write(1, " ", 1);
	if (flag.plus == 1 && !is_double_negative(number))
	{
		if (!is_double_negative(number))
			write(1, "+", 1);
		if (flag.star == 1)
			flag.size.star++;
	}
	str_len = ft_print_with_indent(str, flag.size.star, str_len, 1);
	if (flag.plus || flag.space)
	{
		if ((flag.plus || flag.space) && (flag.size.star >= str_len || (-1) * flag.size.star >= str_len))
			str_len = (flag.size.star > 0) ? flag.size.star : (-1) * (flag.size.star);
		else if (!is_double_negative(number))
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