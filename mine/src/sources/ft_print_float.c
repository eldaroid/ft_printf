/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:42:07 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/13 15:45:55 by fgracefo         ###   ########.fr       */
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


char	*ft_before_long(long double number, int check_dot, t_flag flag, int zero)
{
	int		power;
	int		sign;
	char	*str;
	
	power = ((unsigned int)number == 0 && is_double_negative(number)) ? 2 : ft_power(number, 10);
	if (flag.zero > 0 && zero)
		power = (flag.size.zero >= power) ? flag.size.zero : power;
	if (!(str = (char *)malloc(sizeof(char) * (power + 2 - zero))))
		return (NULL);
	if (check_dot != 1) 
		str[power - zero] = '.';
	str[power + 1] = '\0';
	sign = (number < 0) ? -1 : 1;
	while ((power - zero) > 0)
	{
		power--;
		str[power - zero] = ft_symbol(((long long int)number % 10) * sign);
		number = number / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char	*ft_after_long(long double number, int weight)
{
	char	*str;
	int		power;
	
	power = 0;
	power = weight;
	while (--weight >= 0)
		number *= 10;
	if (!(str = (char *)malloc(sizeof(char) * (power + 1))))
		return (NULL);
	str[power] = '\0';
	// if (number < 0)
	// 	number *= -1;
	while (power > 0)
	{
		power--;
		str[power] = ft_symbol((long long int)number % 10);
		number = (long long int)(number / 10);
	}
	return (str);
}

long double	long_rounding(long double nb, int precision, int sign)
{
	int		i;
	long double	tmp;
	
	if (sign == 0)
		tmp = nb - (unsigned long int)nb;
	else
		tmp = nb - (long long int)nb;
	i = -1;
	while (++i != precision)
		tmp *= 10;
	tmp = (sign) ? tmp - 0.5 : tmp + 0.5;
	while (--precision >= 0)
		tmp /= 10;
	return ((!sign) ? (unsigned long int) nb + tmp : (long long int)nb + tmp);
}

char	*ft_long_float(long double nb, t_flag flag)
{
	char	*before_dot;
	char	*after_dot;
	int			precision;
	long double		before_number;
	long double		after_number;
	// char	*str;

	precision = ((flag.size.dot != 0) ? flag.size.dot : 6);
	if (flag.dot == 1 && flag.size.dot == 0 && precision == 6)
		precision = 0;
	before_number = (is_double_negative(nb)) ? long_rounding(nb, precision, 1) : long_rounding(nb, precision, 0);
	after_number = (is_double_negative(nb)) ? long_rounding(nb - (long long int)nb, precision, 1) * -1 : long_rounding(nb - (long long int)nb, precision, 0);

	after_dot = ft_after_long(after_number, precision);
	
	int str_after = (precision != 0) ? ft_strlen(after_dot) + 1 : 0;
	if (flag.zero == 1 && precision + 1 < str_after)
		before_dot = (precision == 0) ? ft_before_long(before_number, 1, flag, str_after) : ft_before_long(before_number, 0, flag, str_after);
	else
		before_dot = (precision == 0) ? ft_before_long(before_number, 1, flag, 0) : ft_before_long(before_number, 0, flag, 0);
	return (ft_strjoin(before_dot, after_dot));
}

int		ft_print_float(va_list list,t_flag flag)
{
	long double	number;
	char	*str;
	long long	str_len;
	int			k;

	number = (long double)(flag.length.L == 1) ? va_arg(list, long double) : va_arg(list, double);

	if (flag.length.L != 1)
		str = ft_string_float(number,flag);
	else
		str = ft_long_float(number,flag);
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
