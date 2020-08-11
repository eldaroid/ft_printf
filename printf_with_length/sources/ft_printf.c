/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoriainucina <viktoriainucina@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:24:33 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/09 12:14:09 by viktoriainu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


t_flag      ft_parse_length(const char *format, size_t *i, t_flag flag)
{
   if (format[*i] == 'l' && format[(*i) + 1] == 'l')
    {
        flag.length.ll = 1;
        (*i)++;
    }
    else if (format[*i] == 'l' || format[*i] == 'L')
        flag.length.l = 1;
    else if (format[*i] == 'h' && format[(*i) + 1] == 'h')
    {
         flag.length.hh = 1;
        (*i)++;
    }
    else if (format[*i] == 'h')
        flag.length.h = 1;
    else
        (*i)++;
    return (flag);
}


t_flag      ft_parse_flag(const char *format, size_t *i, va_list list, t_flag flag)
{
    while (!(ft_strchr("cspdiuxoXf%", format[*i]))) // f and ll hh
    {
        if (format[*i] == '0')
            flag = ft_parse_flag_zero(format, i, list, flag);
		else if ((format[*i] >= '1' && format[*i] <= '9')
				|| format[*i] == '-' || format[*i] == '*')
			flag = ft_parse_flag_minus(format, i, list, flag);
		else if (format[*i] == '+')
			flag = ft_parse_flag_plus(format, i, list, flag);
		else if (format[*i] == ' ')
			flag = ft_parse_flag_space(format, i, list, flag);
		else if (format[*i] == '.')
			flag = ft_parse_flag_dot(format, i, list, flag);
        else if (format[*i] == '#')
            flag = ft_parse_hash(flag);
		else
        {
            flag = ft_parse_length(format, i, flag);
            (*i)++;
        }
    }
    return (flag);
}

int     ft_parser(const char *format, size_t *i, va_list list)
{
        t_flag      flag;
		
		flag = (t_flag){0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0, 0}};
        flag = ft_parse_flag(format, i, list, flag);
        return (print_type(format, i, list, flag));
}


int     ft_sprintf(const char *format, va_list list)
{
    size_t     i;
    int     len;

    len = 0;
    i = 0;
    while (format[i])
    {
        while (format[i] != '%' && format[i])
        {
            write(1, &format[i], 1);
            i++;
            len++;
        }
        if (format[i] == '%') 
        {
            i++;
            len += ft_parser(format, &i, list);
        }
    }
    return (len);
}

int     ft_printf(const char *format, ...)
{
    int     len;
    va_list list;

    len = 0;
    va_start(list, format);
    len = ft_sprintf(format, list);
    va_end(list);
    return (len);
}