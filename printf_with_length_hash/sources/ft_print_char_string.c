/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:43:44 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/01 19:11:01 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_char(va_list list, t_flag flag)
{
	char	*str;
	int		k;
	int		len;
	
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = (char)va_arg(list, int);
	len = 1;
	k = flag.size.star;
	while (k-- > len)
		write(1, " ", 1);
	return (ft_print_with_indent(str, flag.size.star, 1, 1));
}

int			ft_print_string(va_list list, t_flag flag)
{
	char	*str;
	int		len;
	int		clean;
	int		k;
	
	clean = 0;
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
	return (ft_print_with_indent(str, flag.size.star, len, clean));
}
