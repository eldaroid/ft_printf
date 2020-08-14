/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:24:33 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 13:19:21 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_parse_len(const char *format, size_t *i, va_list list, t_flag flag)
{
	if (format[*i] == 'l' && format[(*i) + 1] == 'l')
	{
		flag.length.ll = 1;
		(*i)++;
	}
	else if (format[*i] == 'l')
		flag.length.l = 1;
	else if (format[*i] == 'L')
		flag.length.L = 1;
	else if (format[*i] == 'z')
		flag.length.l = 'z';
	else if (format[*i] == 'j')
		flag.length.l = 'j';
	else if (format[*i] == 'h' && format[(*i) + 1] == 'h')
	{
		flag.length.hh = 1;
		(*i)++;
	}
	else if (format[*i] == 'h')
		flag.length.h = 1;
	flag.size.star = ft_count_size(format, i, list);
	(*i)++;
	return (flag);
}

t_flag	ft_parse_flag(const char *format, size_t *i, va_list list, t_flag flag)
{
	while (!(ft_strchr("cspdiuxoXfegUZ%", format[*i])) && format[*i])
	{
		if (format[*i] == '0')
			flag = ft_parse_zero(format, i, list, flag);
		else if ((format[*i] >= '1' && format[*i] <= '9')
			|| format[*i] == '-' || format[*i] == '*')
			flag = ft_parse_minus(format, i, list, flag);
		else if (format[*i] == '+')
			flag = ft_parse_plus(format, i, list, flag);
		else if (format[*i] == ' ')
			flag = ft_parse_space(format, i, list, flag);
		else if (format[*i] == '.')
			flag = ft_parse_dot(format, i, list, flag);
		else if (format[*i] == '#')
		{
			flag.hash = 1;
			(*i)++;
		}
		else if (format[*i] == 'l' || format[*i] == 'h'
			|| format[*i] == 'L' || format[*i] == 'j' || format[*i] == 'z')
			flag = ft_parse_len(format, i, list, flag);
		else
			(*i)++;
	}
	return (flag);
}

int		ft_parser(const char *format, size_t *i, va_list list)
{
	t_flag	flag;

	flag = (t_flag){ 0, 0, 0, 0, 0, 0, 0, 0,
		{ 0, 0, 0, 0, 0, 1}, { 0, 0, 0, 0, 0 } };
	flag = ft_parse_flag(format, i, list, flag);
	return (print_type(format, i, list, flag));
}

int		ft_sprintf(const char *format, va_list list)
{
	size_t		i;
	int			len;

	len = 0;
	i = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			len++;
		}
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_parser(format, &i, list);
		}
		else if (format[i + 1] == '\0')
			i++;
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	va_list	list;

	len = 0;
	va_start(list, format);
	len = ft_sprintf(format, list);
	va_end(list);
	return (len);
}
