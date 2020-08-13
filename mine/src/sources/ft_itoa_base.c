/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:39:48 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/13 15:08:29 by fgracefo         ###   ########.fr       */
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
		else if (n == 11)
			return ('b');
		else if (n == 12)
			return ('c');
		else if (n == 13)
			return ('d');
		else if (n == 14)
			return ('e');
		else if (n == 15)
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
	sign = (n < 0) ? -1 : 1;
	if (flag.dot > 0 && flag.size.dot > 0)
		power = (flag.size.dot >= power) ? flag.size.dot + (n < 0) : power;
	else if (flag.zero > 0)
	{
		power = (flag.size.zero >= power) ? flag.size.zero : power;
		if (flag.plus == 1 && flag.size.zero > ft_power(n, base))
		{
			power = (flag.size.zero < flag.size.plus) ? flag.size.plus : flag.size.zero;
			if (sign > 0)
				power--;
		}
	}
	else if (flag.space > 0)
	{
		power = (flag.size.space >= power) ? flag.size.space - 1 : power;
		if (flag.plus == 1 && flag.size.zero > ft_power(n, base))
			power--;
	}
	if (flag.dot > 0 && flag.size.dot == 0 && n == 0)
		power = 0;
	if (flag.type == 'o' && (flag.type == 111 && flag.hash == 1))
		power = ft_power(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (power + 1))))
		return (NULL);
	str[power] = '\0';
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
