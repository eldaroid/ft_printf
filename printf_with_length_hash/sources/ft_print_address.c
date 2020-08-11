/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:42:19 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/10 14:43:21 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_print_address(va_list list, t_flag flag)
{
	unsigned long long	addressint;
	char				*str;
	int					len;
	int		k;
	
	addressint = (unsigned long long)va_arg(list, void *);
	str = ft_itoa_addres(addressint, flag);
	len = ft_strlen(str);
	if (flag.zero && flag.dot && flag.size.zero > flag.size.dot)
		flag.size.star = flag.size.zero;
	k = flag.size.star;
	while (k-- > len)
		write(1, " ", 1);
	return (ft_print_with_indent(str, flag.size.star, len, 1));
}