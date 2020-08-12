/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:43:44 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/12 18:31:13 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_char(va_list list, t_flag flag)
{
	char	*str;
	int		k;
	int		len;
	int		zero;

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

// int		ft_size(t_flag flag, int size)
// {
// 	int		size1;

// 	size1 = size;
// 	if (flag.size.zero > size1)
// 		size1 = flag.size.zero;
// 	if (flag.size.star > size1)
// 		size1 = flag.size.star;
// 	if (flag.size.plus > size1)
// 		size1 = flag.size.plus;
// 	if (flag.size.space > size1)
// 		size1 = flag.size.space;
// 	return (size1);
// }

// char		*ft_string(va_list list, t_flag flag)
// {
// 	int		power;
// 	char	*str;
// 	char	*str2;
// 	int		str_str;

// 	str = va_arg(list, char *);
// 	str_str = ft_strlen(str);
// 	power = (ft_size(flag, str_str) >= str_str) ? ft_size(flag, str_str) : str_str;
// 	if (!(str2 = (char *)malloc(sizeof(char) * (power + 1))))
// 		return (NULL);
// 	if (flag.zero == 1)
// 		ft_bzero(str2, '0', power);
// 	else
// 		ft_bzero(str2, ' ', power);
// 	str2[power] = '\0';
// 	while (str_str > 0)
// 	{
// 		power--;
// 		str_str--;
// 		str2[power] = str[str_str];
// 	}
// 	return (str2);
// }

int			ft_print_string(va_list list, t_flag flag)
{
	char	*str;
	int		len;
	int		clean;
	int		k;
	int		zero;

	clean = 0;
	zero = 0;
	str = va_arg(list, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
		clean = 1;
	}
	len = ft_strlen(str);
	if (flag.dot && flag.size.dot < len && flag.size.dot >= 0)
	{
		len = flag.size.dot;
		if (str[0] == '-')
			len++;
	}
	k = flag.size.star;
	while (k-- > len)
		write(1, " ", 1);
	k = (flag.zero == 1 && flag.size.zero > 0) ? flag.size.zero : k;
	while (k-- > len)
	{
		zero++;
		write(1, "0", 1);
	}
	len = ft_print_with_indent(str, flag.size.star, len, clean);
	return (len + zero);
}
