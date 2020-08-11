/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:50:50 by ashea             #+#    #+#             */
/*   Updated: 2020/07/30 16:02:38 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#   include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_size
{
	int			star;
	int			zero;
	int			dot;
}				t_size;

typedef struct	s_flag
{
	int			star;
	int			zero;
	int			dot;
	t_size		size;
}				t_flag;
int				ft_print_with_indent(char *str, int size_star,
		int str_len, int clean);
int				ft_print_char(va_list list, t_flag flag);
int				ft_print_percent(t_flag flag);
int				print_type(const char *str, size_t *i, va_list list, t_flag		flag);
int				ft_print_string(va_list list, t_flag flag);
int				ft_print_integer(va_list list, t_flag flag);
int				ft_print_unsignedint(va_list list, t_flag flag,
		int base, int is_toupper);
int				ft_print_address(va_list list, t_flag flag);
t_flag			ft_parse_flag(const char *str, size_t *i, va_list list, t_flag	flag);
t_flag			ft_parse_flag_dop(const char *str, size_t *i,
		va_list list, t_flag flag);
int				ft_parse_format(const char *str, size_t *i, va_list list);
int				ft_parse(const char *str, va_list list);
int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *src);
int				ft_toupper(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi_i(const char *str, size_t *i, va_list list);
int				ft_atoi_i_dop(size_t *i, va_list list, int sign);
int				ft_power(long long n, int base);
char			ft_symbol(int n);
char			*ft_itoa_base(long long n, int base, t_flag flag);
char			*ft_itoa_addres(unsigned long long n, t_flag flag);
char			*ft_itoa(int n);

#endif
