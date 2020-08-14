/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:43:45 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 16:33:27 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char			*ft_before_dot(double number, int check_dot,
								t_flag flag, int zero)
{
	int		power;
	int		sign;
	char	*str;

	power = ((unsigned int)number == 0 && is_double_negative(number))
			? 2 : ft_power(number, 10);
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

char			*ft_after_dot(long double nb, int weight)
{
	char			*str;
	int				power;
	long double		after_number;

	after_number = (is_double_negative(nb)) ?
					rounding(nb - (int)nb, weight, 1) * -1 :
					rounding(nb - (int)nb, weight, 0);
	power = 0;
	power = weight;
	while (--weight >= 0)
		after_number *= 10;
	if (!(str = (char *)malloc(sizeof(char) * (power + 1))))
		return (NULL);
	str[power] = '\0';
	while (power > 0)
	{
		power--;
		str[power] = ft_symbol((long long int)after_number % 10);
		after_number = (long long int)(after_number / 10);
	}
	return (str);
}

long double		rounding(long double nb, int precision, int sign)
{
	int			i;
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
	return ((!sign) ? (unsigned long int)nb + tmp : (long long int)nb + tmp);
}

char			*string_of_float(double nb, int precision,
								int str_after, t_flag flag)
{
	char			*before_dot;
	long double		before_number;

	before_number = (is_double_negative(nb)) ? rounding(nb, precision, 1) :
					rounding(nb, precision, 0);
	if (flag.zero == 1 && precision + 1 < str_after)
		before_dot = (precision == 0) ?
					ft_before_dot(before_number, 1, flag, str_after) :
					ft_before_dot(before_number, 0, flag, str_after);
	else
		before_dot = (precision == 0) ?
					ft_before_dot(before_number, 1, flag, 0) :
					ft_before_dot(before_number, 0, flag, 0);
	return (before_dot);
}

char			*ft_string_float(double nb, t_flag flag)
{
	char			*after_dot;
	int				precision;
	char			*before_dot;
	int				str_after;
	char			*str;

	precision = ((flag.size.dot != 0) ? flag.size.dot : 6);
	if (flag.dot == 1 && flag.size.dot == 0 && precision == 6)
		precision = 0;
	after_dot = ft_after_dot(nb, precision);
	str_after = (precision != 0) ? ft_strlen(after_dot) + 1 : 0;
	before_dot = string_of_float(nb, precision, str_after, flag);
	str = ft_strjoin(before_dot, after_dot);
	free(before_dot);
	free(after_dot);
	before_dot = NULL;
	after_dot = NULL;
	return (str);
}
