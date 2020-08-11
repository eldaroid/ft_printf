/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:42:07 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/08 19:17:17 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     is_double_negative(double nb)
{
    unsigned char *c_nb = (unsigned char *)&nb;
    unsigned char minus_part = c_nb[sizeof(double) - 1];
    return (minus_part >> 7);
}

char	*before_dot(double number)
{
	int		power;
	int		sign;
	char	*str;
	
	power = ((unsigned int)number == 0 && is_double_negative(number)) ? 2 : ft_power(number, 10);
	// power = ft_power(number, 10);
	if (!(str = (char *)malloc(sizeof(char) * (power + 2))))
		return (NULL);
	str[power] = '.';
	str[power + 1] = '\0';
	sign = (number < 0) ? -1 : 1;
	while (power > 0)
	{
		power--;
		str[power] = ft_symbol(((int)number % 10) * sign);
		number = number / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

void	*reverse_array(char *str)
{
	char	tmp;
	char	tmp1;
	int		i;
	int		str_len;

	str_len = ft_strlen(str);
	i = 0;
	if (str[i])
		tmp = str[i];
	i++;
	while (str_len / 2 != 0)
	{
		tmp1 = str[str_len - 1];
		str[str_len - 1] = tmp;
		str[i - 1] = tmp1;
		i++; 
		str_len--;
	}
	return (str);	
}

char	*after_dot(double number, int weight)
{
	char	*str;
	int		power;
	
	power = 0;
	// while ((int)(number * 10) % 10 != 0)
	// {
	// 	number *= 10;
	// 	power++;
	// }
	power = weight;
	while (--weight >= 0)
		number *= 10;
	if (!(str = (char *)malloc(sizeof(char) * (power + 1))))
		return (NULL);
	str[power] = '\0';
	// while ()
	while (power > 0)
	{
		power--;
		str[power] = ft_symbol((int)number % 10);
		number = (int)(number / 10);
	}
//	str = reverse_array(str);
	return (str);
}

double	rounding(double nb, int precision)
{
	int		i;
	double	tmp;
	long int l;

	l = (long int)nb;
	tmp = nb - (unsigned long int)nb;
	i = -1;
	while (++i != precision)
		tmp *= 10;
	tmp += 0.5;
	while (--precision >= 0)
		tmp /= 10;
	return ((unsigned long int) nb + tmp);
}

double	rounding_minus(double nb, int precision)
{
	int		i;
	double	tmp;
	long int l;
	double		k;
	double		test;

	l = (long int)nb;
	tmp = nb - (long int)nb;
	i = -1;
	while (++i != precision)
		tmp *= 10;
	tmp -= 0.5;
	while (--precision >= 0)
		tmp /= 10;
	k = (long int)nb;
	test = (long int)nb+ tmp;
	return ((long int)nb + tmp);
}

// long		check_sign(double nb)
// {
// 	long		sign;

// 	sign = (long)nb >> 63;
// 	return (sign);
// }

// void    print_bits(unsigned long long octet)
// {
//     unsigned long long z = ((18446744073709551615 - 1) / 2) + 1, oct = octet;

//     while (z > 0)
//     {
//         if (oct & z)
//             write(1, "1", 1);
//         else
//             write(1, "0", 1);
//         z >>= 1;
//     }
// }

int		ft_print_float(va_list list,t_flag flag)
{
	double	number;
	char	*before;
	char	*after;
	char	*str;
	long long	str_len;
	int			precision;
	double		before_number;
	double		i;
	// int			k;
	
	number = va_arg(list, double);
	precision = ((flag.size.dot != 0) ? flag.size.dot : 6);
	// number = rounding(number, ft_power((int)number, 10)); // ft_power - сколько знаков до запятой

	// k = (va_arg(list, double) == -0) ? 1 : 0;
	// print_bits(number);
	// printf("sign = %d\n", sign);
	before_number = (number < 0) ?  rounding_minus(number, precision) : rounding(number, precision);
	// before_number = rounding_minus(number, precision);
	// before_number = rounding(number, precision);
	// // test = ((int)before_number) * (-1);
	before = before_dot(before_number);
	i = (number < 0 || number == -0) ?  rounding_minus(number - (int)number, precision) * -1 : rounding(number - (int)number, precision);
	after = after_dot(i, precision);
	
	str = ft_strjoin(before, after);
	str_len = ft_strlen(str);
	write(1, str, str_len);
	// write(1, ft_strjoin(before_dot((int)number, flag), after_dot(number - (int)number)), 
	// 		ft_strlen(ft_strjoin(before_dot((int)number, flag), after_dot(number - (int)number))));
	return (str_len);
}