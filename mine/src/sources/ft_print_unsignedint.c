/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:41:31 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/11 21:13:28 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_upower(unsigned long long int n, int base)
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

char		*ft_utoa_base(unsigned long long int n, int base, t_flag flag)
{
	int		power;
	int		sign;
	char	*str;

	power = ft_upower(n, base);
	if (flag.dot > 0 && flag.size.dot > 0)
		power = (flag.size.dot >= power) ? flag.size.dot + (n < 0) : power;
	else if (flag.zero > 0)
	{
		power = (flag.size.zero >= power) ? flag.size.zero : power;
		if (flag.plus == 1 && flag.size.zero > ft_upower(n, base))
			power--;
	}
	if (flag.dot > 0 && flag.size.dot == 0 && n == 0)
		power = 0;
	if (flag.type == 'o' && (flag.type == 111 && flag.hash == 1) && flag.size.dot == 0)
		power = ft_upower(n, base);
	if (flag.type == 'o' && (flag.size.dot >= power) && flag.hash == 1)
		power--;
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

int					ft_print_unsignedint(va_list list,
					t_flag flag, int base, int is_toupper)
{
	unsigned long long int	u;
	char					*str;
	int						i;
	int						len;
	int						k;

	u = (flag.type != 'U' && flag.type != 'j') ? ft_length_uint(list, flag) : va_arg(list, long long int);;
	str = ft_utoa_base(u, base, flag);
	len = ft_strlen(str);
	if (len != flag.size.zero)
		str = (flag.hash == 1 && u != 0) ? ft_strjoin(ft_hash(ft_power(u, base), flag), str) : str;
	else if (flag.hash == 1 && u != 0)
	{
		str[0] = '0';
		str[1] = 'x';
	}
	i = 0;
	len = ft_strlen(str);
	if (is_toupper)
		while (str[i] != '\0')
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	if (flag.zero && flag.dot && flag.size.zero > flag.size.dot)
		flag.size.star = flag.size.zero;
	else if (((flag.minus_plus == 4 && flag.hash == 1) || (flag.minus_plus == 4 && flag.hash == 1)) && flag.size.star > 0)
		flag.size.star = flag.size.star * (-1);
	k = flag.size.star;
	while (k-- > len)
		write(1, " ", 1);
	return (ft_print_with_indent(str, flag.size.star, len, 1));
}
