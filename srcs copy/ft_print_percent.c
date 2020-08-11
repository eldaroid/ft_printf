/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 02:29:51 by ashea             #+#    #+#             */
/*   Updated: 2020/07/07 17:08:02 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_percent(t_flag flag)
{
	int	count;

	count = 0;
	while (flag.size.zero > 1)
	{
		flag.size.zero--;
		count++;
		write(1, "0", 1);
	}
	return (ft_print_with_indent("%", flag.size.star, 1, 0) + count);
}
