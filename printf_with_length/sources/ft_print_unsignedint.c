/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoriainucina <viktoriainucina@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:41:31 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/09 11:37:51 by viktoriainu      ###   ########.fr       */
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
	int				k;

	u = ft_length_uint(list, flag);
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
	k = flag.size.star;
	while (k-- > len)
		write(1, " ", 1);
	return (ft_print_with_indent(str, flag.size.star, len, 1));
}
