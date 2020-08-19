/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:04:40 by fgracefo          #+#    #+#             */
/*   Updated: 2019/09/20 19:04:06 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int n)
{
	int		count;

	count = 1;
	if (n)
	{
		while (n / 10)
		{
			n /= 10;
			count++;
		}
		return (count);
	}
	else if (n == 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		size;

	size = 1 + count_num(n);
	if (!(num = ft_memalloc(size + (n < 0 ? 1 : 0))))
		return (0);
	if (n < 0)
	{
		num[0] = '-';
		if (n == -2147483648)
		{
			num[--size] = '8';
			n /= 10;
		}
		size++;
		n *= -1;
	}
	while (--size > 0)
	{
		if (num[size - 1] != '-')
			num[size - 1] = n % 10 + 48;
		n /= 10;
	}
	return (num);
}
