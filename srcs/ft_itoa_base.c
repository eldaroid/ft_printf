/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:36:34 by ashea             #+#    #+#             */
/*   Updated: 2020/07/07 17:12:35 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_power(long long n, int base)
{
	int		power;

	power = 0;
	if (n <= 0)
		power = 1;
	while (n != 0)
	{
		n = n / base;
		power++;
	}
	return (power);
}

char		ft_symbol(int n)
{
	if (n > 0 && n < 10)
		return (n + '0');
	else
	{
		if (n == 10)
			return ('a');
		if (n == 11)
			return ('b');
		if (n == 12)
			return ('c');
		if (n == 13)
			return ('d');
		if (n == 14)
			return ('e');
		if (n == 15)
			return ('f');
	}
	return ('0');
}

char		*ft_itoa_base(long long n, int base, t_flag flag)
{
	int		power;
	int		sign;
	char	*str;

	power = ft_power(n, base);
	if (flag.dot > 0 && flag.size.dot > 0)
		power = (flag.size.dot >= power) ? flag.size.dot + (n < 0) : power;
	else if (flag.zero > 0)
		power = (flag.size.zero >= power) ? flag.size.zero : power;
	if (flag.dot > 0 && flag.size.dot == 0 && n == 0)
		power = 0;
	if (!(str = (char *)malloc(sizeof(char) * (power + 1))))
		return (NULL);
	str[power] = '\0';
	sign = (n < 0) ? -1 : 1;
	while (power > 0)
	{
		power--;
		str[power] = ft_symbol(n % base * sign);
		n = n / base;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_addres(unsigned long long n, t_flag flag)
{
	int		power;
	char	*str;

	power = ft_power(n, 16);
	if (flag.dot > 0 && flag.size.dot > 0)
		power = (flag.size.dot >= power) ? flag.size.dot + (n < 0) : power;
	else if (flag.zero > 0)
		power = (flag.size.zero >= power) ? flag.size.zero : power;
	if (flag.dot > 0 && flag.size.dot == 0 && n == 0)
		power = 0;
	if (!(str = (char *)malloc(sizeof(char) * (power + 3))))
		return (NULL);
	str[power + 2] = '\0';
	while (power > 0)
	{
		power--;
		str[power + 2] = ft_symbol(n % 16);
		n = n / 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char		*ft_itoa(int n)
{
	int		power;
	int		sign;
	char	*str;

	power = ft_power(n, 10);
	if (!(str = (char *)malloc(sizeof(char) * power + 1)))
		return (NULL);
	str[power] = '\0';
	sign = (n < 0) ? -1 : 1;
	while (power > 0)
	{
		power--;
		str[power] = n % 10 * sign + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
