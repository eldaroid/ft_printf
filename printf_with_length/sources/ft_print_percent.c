/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:42:54 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/01 19:04:16 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_percent(t_flag flag)
{
	int	count;
	int		k;
	int		len;

	count = 0;
	while (flag.size.zero > 1)
	{
		flag.size.zero--;
		count++;
		write(1, "0", 1);
	}
	k = flag.size.star;
	len = 1;
	while (k-- > len)
		write(1, " ", 1);
	return (ft_print_with_indent("%", flag.size.star, 1, 0) + count);
}
