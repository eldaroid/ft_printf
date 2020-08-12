/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:22:43 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/12 18:30:57 by fgracefo         ###   ########.fr       */
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

// int j =  ft_printf("%- 10.#0+d\n", 256);
// int i =  printf("%- 10.#0+d\n", 256);

// ft_printf("%-+10.5d", 4242);
// printf("%-+10.5d", 4242);z


// int k =  ft_printf("%+-10.5d\n", 4242);
// int l =  printf("%+-10.5d\n", 4242);

// printf("3 = %d\n", k);
// printf("4 = %d\n", l);

// printf("%+d\n", 42);
// ft_printf("%+d\n", 42);

// int i = ft_printf("%-+10.5d\n", 4242);
// int j = printf("%-+10.5d\n", 4242);


// ft_printf("%d", -1);

// ft_printf("%Z");
// printf("%Z");
	

	// 314 tests 6 ./test bonus_f

	// int i = printf("%jx\n", 4294967296);
	// int j = ft_printf("%jx\n", 4294967296);

	// int i = ft_printf("%010s\n", "this");
	// int j = printf("%010s\n", "this");
// ft_printf("%0+5d", -42);
// ft_printf("%010s is a string", "this");
// ft_printf("% Z", 42);
// ft_printf("%");
// ft_printf("%05c", 42);
// int i = ft_printf("1%010s is a string\n", "this");
// int j = printf("2%010s is a string\n", "this");
//  28. FAIL ft_printf("%5+d", 42);                        -> "  +42"
//   29. FAIL ft_printf("%5+d", -42);                       -> "  -42"
//   30. FAIL ft_printf("%-5+d", 42);
//   32. FAIL ft_printf("%-5+d", -42);
	// printf("3 = %d\n", i);
	// printf("4 = %d\n", j);
    return (0);
}