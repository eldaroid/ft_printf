/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:31:06 by ashea             #+#    #+#             */
/*   Updated: 2020/07/07 17:09:46 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_unsignedint(va_list list,
		t_flag flag, int base, int is_toupper)
{
	unsigned int	u;
	char			*str;
	int				i;
	int				len;

	u = va_arg(list, unsigned int);
	str = ft_itoa_base(u, base, flag);
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
	return (ft_print_with_indent(str, flag.size.star, len, 1));
}
