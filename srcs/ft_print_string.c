/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:30:15 by ashea             #+#    #+#             */
/*   Updated: 2020/07/07 17:08:59 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_string(va_list list, t_flag flag)
{
	char	*str;
	int		len;
	int		clean;

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
	return (ft_print_with_indent(str, flag.size.star, len, clean));
}
