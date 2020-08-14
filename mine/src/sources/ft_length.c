/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:12:41 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 16:33:33 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int							check_undefine(t_flag flag)
{
	if (flag.type != 'U' && flag.type != 'j' && flag.length.l != 'j')
		return (1);
	else
	{
		return (0);
	}
}

long long int				ft_lenint(va_list list, t_flag flag)
{
	long long int			nbr;

	nbr = va_arg(list, long long int);
	if (flag.length.ll == 1)
		nbr = (long long int)nbr;
	else if (flag.length.l == 1)
		nbr = (long int)nbr;
	else if (flag.length.h == 1)
		nbr = (short int)nbr;
	else if (flag.length.hh == 1)
		nbr = (char)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

unsigned long long int		ft_length_uint(va_list list, t_flag flag)
{
	unsigned long long int	nbr;

	nbr = va_arg(list, unsigned long long int);
	if (flag.length.hh == 1)
		nbr = (unsigned char)nbr;
	else if (flag.length.h == 1 && flag.type != 'U')
		nbr = (unsigned short int)nbr;
	else if (flag.length.l == 1)
		nbr = (unsigned long int)nbr;
	else if (flag.length.ll == 1)
		nbr = (unsigned long long int)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

int							check_count(int size_star, int str_len)
{
	int						count;

	count = str_len;
	if (size_star > str_len || (-1) * size_star > str_len)
		count = (size_star > 0) ? size_star : (-1) * size_star;
	return (count);
}

void						ft_free(int clean, char *str)
{
	if (clean)
	{
		free(str);
		str = NULL;
	}
}
