/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:31:31 by akelli            #+#    #+#             */
/*   Updated: 2020/08/10 14:43:23 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char     *ft_hash(int power, t_flag flag)
{
    char *str;

    if (flag.hash && flag.type == 'x')
    {
        str[power + 2] = '\0';
        str[0] = '0';
        str[1] = 'x';
    }
    else if (flag.hash && flag.type == 'X')
    {
        str[power + 2] = '\0';
        str[0] = '0';
        str[1] = 'X';
    }
    else if (flag.hash && flag.type == 'o')
    {
        str[power + 2] = '\0';
        str[0] = '0';
    }
    return (str);
}