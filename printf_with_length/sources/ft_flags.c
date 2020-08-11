/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoriainucina <viktoriainucina@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:49:50 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/09 11:33:19 by viktoriainu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag  ft_parse_flag_zero(const char *format, size_t *i, va_list list, t_flag  flag)
{
	size_t	k;

	k = 0;
    flag.zero = 1;
    flag.size.zero = ft_count_size(format, i, list);
	if 	(flag.size.zero == 0 && format[(*i)] != '-')
	{
		k = (*i) + 1;
		flag.size.zero = ft_count_size(format, &k, list);
		// flag.size.zero = flag.size.zero - 1;
		
	}
	if (flag.size.zero < 0)
	{
		flag.star = 1;
		flag.size.star = flag.size.zero;
	}
    return (flag);
}

t_flag  ft_parse_flag_minus(const char *format, size_t *i, va_list list, t_flag  flag)
{
	flag.star = 1;
	flag.size.star = ft_count_size(format, i, list);
	if (format[*i] == '+')
		flag.minus_plus = 2;
	return (flag);
}

t_flag  ft_parse_flag_plus(const char *format, size_t *i, va_list list, t_flag  flag)
{
	flag.plus = 1;
	// if (format[*i] == '+')
	// 	flag.minus_plus++;
	flag.size.plus = ft_count_size(format, i, list);
	return (flag);
}

t_flag  ft_parse_flag_space(const char *format, size_t *i, va_list list, t_flag  flag)
{
	flag.space = 1;
	flag.size.space = ft_count_size(format, i, list);
	return (flag);
}

t_flag  ft_parse_flag_dot(const char *format, size_t *i, va_list list, t_flag  flag)
{
	flag.dot = 1;
	flag.size.dot = ft_count_size(format, i, list);
	return (flag);
}

t_flag	ft_parse_hash(t_flag  flag)
{
	flag.hash = 1;
	return (flag);
}