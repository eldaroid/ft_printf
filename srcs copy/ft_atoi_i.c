/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:35:41 by ashea             #+#    #+#             */
/*   Updated: 2020/07/07 15:51:24 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_i(const char *str, size_t *i, va_list list)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	if (str[*i] == '0' || str[*i] == '.')
		(*i)++;
	if (str[*i] == '*')
	{
		(*i)++;
		return (va_arg(list, int));
	}
	if (str[*i] == '-')
	{
		(*i)++;
		sign = -1;
		if (str[*i] == '*')
			return (ft_atoi_i_dop(i, list, sign));
	}
	while (str[*i] != '\0' && str[*i] <= '9' && str[*i] >= '0')
		n = n * 10 + (str[(*i)++] - '0');
	return (n * sign);
}

int		ft_atoi_i_dop(size_t *i, va_list list, int sign)
{
	int	n;

	n = 0;
	(*i)++;
	n = va_arg(list, int);
	return ((n > 0) ? n * sign : n);
}
