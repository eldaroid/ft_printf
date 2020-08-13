/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:27:47 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/13 18:26:12 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_minus_star(size_t *i, va_list list, int sign)
{
	int	n;

	n = 0;
	(*i)++;
	n = va_arg(list, int);
	return ((n > 0) ? n * sign : n);
}

int		check_all(const char *format, size_t *i, va_list list, int count)
{
	if (format[*i] == '*')
	{
		(*i)++;
		return (va_arg(list, int));
	}
	while (format[*i] >= '0' && format[*i] <= '9' && format[*i])
	{
		count = count * 10 + (format[*i] - '0');
		(*i)++;
	}
	return (count);
}

int		ft_count_size(const char *format, size_t *i, va_list list)
{
	int	sign;
	int	count;

	count = 0;
	sign = 1;
	if (format[*i] == '-' || format[*i] == '+'
		|| format[*i] == '.' || format[*i] == '0' || format[*i] == ' ')
	{
		if (format[*i] == '-')
		{
			sign = -1;
			if (format[(*i) + 1] == '*')
			{
				(*i)++;
				return (ft_atoi_minus_star(i, list, sign));
			}
		}
		(*i)++;
	}
	count = check_all(format, i, list, count);
	return (count * sign);
}
