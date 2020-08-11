/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:30:49 by ashea             #+#    #+#             */
/*   Updated: 2020/07/07 17:08:42 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_integer(va_list list, t_flag flag)
{
	int		i;
	char	*str;
	int		len;

	i = va_arg(list, int);
	str = ft_itoa_base(i, 10, flag);
	len = ft_strlen(str);
	if (flag.zero && flag.dot && flag.size.zero > flag.size.dot)
		flag.size.star = flag.size.zero;
	return (ft_print_with_indent(str, flag.size.star, len, 1));
}
