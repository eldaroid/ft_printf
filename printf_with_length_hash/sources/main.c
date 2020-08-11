/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:22:43 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/10 14:41:49 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main(void)
{
	// int i = printf("%.16f\n", 3.03);
	// int j = ft_printf("%.2f\n", -3.03);

	// printf("%d\n", i);
	// printf("%d\n", j);

	int i = printf("not my 1 = %#o\n", 1);
	int j = ft_printf("my = %#o\n", 1);

	// printf("%d\n", i);
	printf("my = %d\n", i);
	printf("my = %d\n", j);
	
	// 233 tests ./test bonus_f

	
// ft_printf("%0+5d", -42);
// ft_printf("%010s is a string", "this");
// ft_printf("% Z", 42);
// ft_printf("%");
//  28. FAIL ft_printf("%5+d", 42);                        -> "  +42"
//   29. FAIL ft_printf("%5+d", -42);                       -> "  -42"
//   30. FAIL ft_printf("%-5+d", 42);
//   32. FAIL ft_printf("%-5+d", -42);
    return (0);
}