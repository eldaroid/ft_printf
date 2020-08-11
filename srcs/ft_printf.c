/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:33:30 by ashea             #+#    #+#             */
/*   Updated: 2020/07/30 16:56:57 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			ft_parse_flag(const char *str, size_t *i, va_list list, t_flag	flag)
{
	while (ft_strchr("cspdiuxoX%", (int)str[*i]) == NULL)
	{
		if (str[*i] == '0')
		{
			flag = ft_parse_flag_dop(str, i, list, flag);
		}
		else if ((str[*i] >= '1' && str[*i] <= '9')
				|| str[*i] == '-' || str[*i] == '*' || str[*i] == ' ' )
		{
			flag.star = 1;
			flag.size.star = ft_atoi_i(str, i, list);
		}
		else if (str[*i] == '.')
		{
			flag.dot = 1;
			flag.size.dot = ft_atoi_i(str, i, list);
		}
		else
			(*i)++;
	}
	return (flag);
}

t_flag			ft_parse_flag_dop(const char *str, size_t *i,
		va_list list, t_flag flag)
{
	flag.zero = 1;
	flag.size.zero = ft_atoi_i(str, i, list);
	if (flag.size.zero < 0)
	{
		flag.star = 1;
		flag.size.star = flag.size.zero;
	}
	return (flag);
}

int				print_type(const char *str, size_t *i, va_list list, t_flag		flag)
{
	int			count;

	count = 0;
	if (str[*i] == 'd' || str[*i] == 'i')
		count += ft_print_integer(list, flag);
	if (str[*i] == 'u')
		count += ft_print_unsignedint(list, flag, 10, 0);
	if (str[*i] == 'x')
		count += ft_print_unsignedint(list, flag, 16, 0);
	if (str[*i] == 'X')
		count += ft_print_unsignedint(list, flag, 16, 1);
	if (str[*i] == 'p')
		count += ft_print_address(list, flag);
	if (str[*i] == '%')
		count += ft_print_percent(flag);
	if (str[*i] == 'c')
		count += ft_print_char(list, flag);
	if (str[*i] == 's')
		count += ft_print_string(list, flag);
	(*i)++;
	return (count);
}

int				ft_parse_format(const char *str, size_t *i, va_list list)
{
	t_flag		flag;
	
	flag = (t_flag){0, 0, 0, {0, 0, 0}};
	flag = ft_parse_flag(str, i, list, flag);
	return (print_type(str, i, list, flag));
}

int				ft_parse(const char *str, va_list list)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
			count++;
		}
		if (str[i] == '%')
		{
			i++;
			count += ft_parse_format(str, &i, list);
		}
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list		list;
	int			count;

	count = 0;
	va_start(list, format);
	count = ft_parse(format, list);
	va_end(list);
	return (count);
}
