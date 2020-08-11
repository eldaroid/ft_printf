/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:10:19 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/10 14:45:28 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				division_by_type(int type, va_list list, t_flag flag, int count)
{
	flag.type = type;
	if (type == 'd' || type == 'i')
			count += ft_print_integer(list, flag);
	else if (type == 'u')
		count += ft_print_unsignedint(list, flag, 10, 0);
	else if (type == 'x') // # used
		count += ft_print_unsignedint(list, flag, 16, 0);
	else if (type == 'X') // # used
		count += ft_print_unsignedint(list, flag, 16, 1);
	else if (type == 'p')
		count += ft_print_address(list, flag);
	else if (type == '%')
		count += ft_print_percent(flag);
	else if (type == 'c')
		count += ft_print_char(list, flag);
	else if (type == 's')
		count += ft_print_string(list, flag);
	else if (type == 'f')
		count += ft_print_float(list,flag);
	else if (type == 'o') // # used
		count += ft_print_unsignedint(list, flag, 8, 0);
	return(count);
}

int				print_type(const char *str, size_t *i, va_list list, t_flag	flag)
{
	int			count;
	
	count = 0;
	count = division_by_type(str[*i], list, flag, count);
	(*i)++;
	return (count);
}