/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:41:31 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 16:33:54 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		ft_check_power(t_flag flag, unsigned long long int n, int base)
{
	int						power;

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
	if (flag.type == 'o' && (flag.type == 111 && flag.hash == 1)
		&& flag.size.dot == 0)
		power = ft_upower(n, base);
	if (flag.type == 'o' && (flag.size.dot >= power) && flag.hash == 1)
		power--;
	return (power);
}

char	*ft_utoa_base(unsigned long long int n, int base, t_flag flag)
{
	int						power;
	int						sign;
	char					*str;

	power = ft_check_power(flag, n, base);
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

int		new_star(t_flag flag, int len)
{
	int						k;

	if (flag.zero && flag.dot && flag.size.zero > flag.size.dot)
		flag.size.star = flag.size.zero;
	else if (((flag.minus_plus == 4 && flag.hash == 1)
		|| (flag.minus_plus == 4 && flag.hash == 1)) && flag.size.star > 0)
		flag.size.star = flag.size.star * (-1);
	k = flag.size.star;
	while (k-- > len)
		write(1, " ", 1);
	return (flag.size.star);
}

char	*new_string(t_flag flag, int base, va_list list)
{
	unsigned long long int	u;
	char					*str;
	int						len;
	char					*hash;
	char					*str1;

	u = (check_undefine(flag)) ? ft_length_uint(list, flag)
		: va_arg(list, long long int);
	str1 = ft_utoa_base(u, base, flag);
	len = ft_strlen(str1);
	str = str1;
	hash = ft_hash(ft_power(u, base), flag);
	if (len != flag.size.zero && flag.hash == 1 && u != 0)
	{
		str = ft_strjoin(hash, str1);
		free(str1);
	}
	else if (flag.hash == 1 && u != 0)
	{
		str[0] = '0';
		str[1] = 'x';
	}
	free(hash);
	return (str);
}

int		ft_print_unsint(va_list list, t_flag flag, int base, int is_toupper)
{
	char					*str;
	int						i;
	int						len;

	str = new_string(flag, base, list);
	i = 0;
	len = ft_strlen(str);
	if (is_toupper)
		while (str[i] != '\0')
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	flag.size.star = new_star(flag, len);
	return (ft_print_with_indent(str, flag.size.star, len, 1));
}
