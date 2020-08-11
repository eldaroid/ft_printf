/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:22:43 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/01 19:08:28 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdio.h>
// 0.1 + 0.2 = 0.3000000000000001230000000
int     main(void)
{
	// printf("%s\n", "gav1in");
	// ft_printf("%s\n", "gav2in");
	printf("%5c1\n", ' ');
	ft_printf("%5c2\n", ' ');
	// printf("%-*s\n", 32, "abc");
	// ft_printf("%-*s\n", 32, "abc");
	// printf("%-*.*s\n", 7, 3, "yolo");
	// ft_printf("%-*.*s\n", 7, 3, "yolo");
	// printf("%-*d\n", -5, 123);
	// 	ft_printf("%-*d\n", -5, 123);
    // printf("% -+d", -120);
    // printf("{%d}\n", printf("\033[1;32mTest 1 => \033[0m|%f||%F|", 1.42, 1.42));
	// printf("{%d}\n", printf("\033[1;32mTest 2 => \033[0m|%f||%F|", -1.42, -1.42));  
    // ft_printf("%08.3d\n", 123);
    // printf("%.17f\n", 0.1 + 0.2);
    return (0);
}