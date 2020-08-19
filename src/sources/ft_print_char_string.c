/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:04:18 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 16:33:44 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int			ft_print_char(va_list list, t_flag flag)
{
	char		*str;
	int			k;
	int			len;
	int			zero;

	zero = 0;
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = (char)va_arg(list, int);
	len = 1;
	k = flag.size.star;
	while (k-- > len)
		write(1, " ", 1);
	k = (flag.zero == 1 && flag.size.zero > 0) ? flag.size.zero : k;
	while (k-- > len)
	{
		zero++;
		write(1, "0", 1);
	}
	len = ft_print_with_indent(str, flag.size.star, 1, 1);
	return (len + zero);
}

size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int			check_len(int len, t_flag flag, char *str)
{
	len = ft_strlen(str);
	if (flag.dot && flag.size.dot < len && flag.size.dot >= 0)
	{
		len = flag.size.dot;
		if (str[0] == '-')
			len++;
	}
	return (len);
}

int			print_zero(int k, int len, int zero)
{
	while (k-- > len)
	{
		zero++;
		write(1, "0", 1);
	}
	return (zero);
}

int			ft_print_string(va_list list, t_flag flag)
{
	char		*str;
	int			len;
	int			clean;
	int			k;
	int			zero;

	clean = 0;
	zero = 0;
	str = va_arg(list, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
		clean = 1;
	}
	len = check_len(0, flag, str);
	k = flag.size.star;
	while (k-- > len)
		write(1, " ", 1);
	k = (flag.zero == 1 && flag.size.zero > 0) ? flag.size.zero : k;
	zero = print_zero(k, len, zero);
	len = ft_print_with_indent(str, flag.size.star, len, clean);
	return (len + zero);
}
