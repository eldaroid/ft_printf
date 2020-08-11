/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:22:43 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/11 21:56:49 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int     main(void)
{
	// int i = printf("%.16f\n", 3.03);
	// int j = ft_printf("%.2f\n", -3.03);
	// int i = printf("not my = %.0f\n", 2.5); //сделать с андреем
	// int j = ft_printf("my = %.0f\n", 2.5);
	// ("%.0f", -0.0);
	// ("%f", -0.0);
	// ("%.8f", -0.0);

	// printf("%.0e", -5.5);
	// printf("%.0e", -5.5);

	// int i = printf("1!%lld\n", 7);
	// int j = ft_printf("2!%lld\n", 7);

	// int i = printf("%#.o, %#.0o\n", 0, 0);
	
	// printf("o1 = %#.3o\n", 1);
	// ft_printf("o2 = %#.3o\n", 1);

// int i =  printf("% hZ\n");
// int j =  ft_printf("% hZ\n");

// int j =  ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
// int i =  printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);

// printf("3 = %d\n", i);
// printf("4 = %d\n", j);

// ft_printf("%Z");
// printf("%Z");


// printf("1 = %0+5d\n", 42);
// ft_printf("2 = %0+5d\n", 42);
// printf("3 = %0+5d\n", -42);
// ft_printf("4 = %0+5d\n", -42);

// ft_printf("%Z");
// ft_printf("%Z");

// printf("% Z", "test");
// ft_printf("% Z", "test");

// ft_printf("%#08x", 42);                       -> "0x00002a"
// ft_printf("%-#6o", 2500);                     -> "04704 "
// ft_printf("%0+5d", 42);                       -> "+0042"
// ft_printf("%0+5d", -42);                      -> "-0042"

// printf("%ld", (long)INT_MAX + 1);

	// printf("a1 = %#.o, %#.0o\n", 0, 0);
	// ft_printf("a2 = %#.o, %#.0o\n", 0, 0);

	// printf("b1 = %.o, %.0o\n", 0, 0);
	// ft_printf("b2 = %.o, %.0o\n", 0, 0);

	// printf("s1 = %.d, %.0d\n", 0, 0);
	// ft_printf("s2 = %.d, %.0d\n", 0, 0);


	// printf("1!%d\n", i);
	// printf("2!%d\n", j);
	
	// int i = printf("%\n");
	// int j = ft_printf("%");

	// printf("1!%d\n", i);
	// printf("2!%d\n", j);
// 	%05.0f", -0.0
// %05.1f", 7.3

	//mine
	// ("%#.0f", -0.0);
	// ("%+.0f", 0.0);
	// ("%+.0f", -0.0);
	// ("%+.3f", 0.0);
	// ("%+.3f", -0.0);
	// ("%5.0f", 0.0);
	// ("%05.0f", 0.0);
	// ("%05.1f", -7.3);
	// ("%-5.3f", -0.0);
	// ("%-5.0f", 7.3);
	

	// 314 tests 6 ./test bonus_f

	
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