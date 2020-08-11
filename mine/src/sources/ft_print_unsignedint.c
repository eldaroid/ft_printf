/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:41:31 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/10 20:37:44 by fgracefo         ###   ########.fr       */
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
	str = (flag.hash == 1 && u != 0) ? ft_strjoin(ft_hash(ft_power(u, base), flag), str) : str;
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
