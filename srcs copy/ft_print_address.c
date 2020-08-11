/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:31:23 by ashea             #+#    #+#             */
/*   Updated: 2020/07/07 17:08:22 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_print_address(va_list list, t_flag flag)
{
	unsigned long long	addressint;
	char				*str;
	int					len;

	addressint = (unsigned long long)va_arg(list, void *);
	str = ft_itoa_addres(addressint, flag);
	len = ft_strlen(str);
	if (flag.zero && flag.dot && flag.size.zero > flag.size.dot)
		flag.size.star = flag.size.zero;
	return (ft_print_with_indent(str, flag.size.star, len, 1));
}
