/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:38:33 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/10 14:40:48 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#   define FT_PRINTF_H

#   include <stdarg.h>
#   include <stdio.h>
# 	include <stdlib.h>
#   include <unistd.h>
#   include <float.h>

typedef struct s_length
{
    int     ll;
    int     hh;
    int     l;
    int     h;
}           t_length;

typedef struct  s_size
{
    int     star;
    int     zero;
	int     plus;
	int     space;
    int     dot;
}           t_size;

// star - !'-'!, '+', !'weight'!, ?'#'?, !'*'!

typedef struct  s_flag
{
    int     star;
    int     zero;
	int     plus;
	int     space;
    int     dot;
	int		minus_plus;
    int     hash;
    int    type;
    t_length length;
    t_size  size;
}           t_flag;

int     	ft_printf(const char *format, ...);
int			print_type(const char *str, size_t *i, va_list list, t_flag flag);
int     	ft_count_size(const char *format, size_t *i, va_list list);
t_flag  	ft_parse_flag_zero(const char *format, size_t *i, va_list list, t_flag  flag);
t_flag  	ft_parse_flag(const char *format, size_t *i, va_list list, t_flag flag);
int     	ft_parser(const char *format, size_t *i, va_list list);
int			ft_atoi_minus_star(size_t *i, va_list list, int sign);
int    		ft_sprintf(const char *format, va_list list);
t_flag  	ft_parse_flag_plus(const char *format, size_t *i, va_list list, t_flag  flag);
t_flag  	ft_parse_flag_dot(const char *format, size_t *i, va_list list, t_flag  flag);
t_flag  	ft_parse_flag_space(const char *format, size_t *i, va_list list, t_flag  flag);
t_flag  	ft_parse_flag_minus(const char *format, size_t *i, va_list list, t_flag  flag);
char		*ft_strchr(const char *str, int c);
int			ft_power(long long n, int base);
char		ft_symbol(int n);
char		*ft_itoa_base(long long n, int base, t_flag flag);
char		*ft_itoa_addres(unsigned long long n, t_flag flag);
char		*ft_itoa(int n);
int			ft_print_address(va_list list, t_flag flag);
int			ft_print_char(va_list list, t_flag flag);
int			ft_print_string(va_list list, t_flag flag);
int			ft_print_integer(va_list list, t_flag flag);
int			ft_print_percent(t_flag flag);
int			ft_print_unsignedint(va_list list,
			t_flag flag, int base, int is_toupper);
int			ft_power(long long n, int base);
char		ft_symbol(int n);
size_t		ft_strlen(const char *s);
int			ft_toupper(int c);
char		*ft_strdup(const char *src);
int			ft_print_with_indent(char *str, int size_star, int str_len, int clean);
char		            *ft_itoa_base(long long n, int base, t_flag flag);
char		            *ft_itoa_addres(unsigned long long n, t_flag flag);
char		            *ft_itoa(int n);
int			            division_by_type(int type, va_list list, t_flag flag, int count);
int			            size_flags(t_flag flag, int	k);
int			            ft_print_float(va_list list,t_flag flag);
char		            *before_dot(double number);
char		            *after_dot(double number, int weight);
char		            *ft_strjoin(char const *s1, char const *s2);
int			            check_size(t_flag flag);
void		            *reverse_array(char *str);
double		            rounding(double nb, int precision);
unsigned long long int      ft_length_uint(va_list list, t_flag flag);
long long int		    ft_length_int(va_list list, t_flag flag);
t_flag	                ft_parse_hash(t_flag  flag);
t_flag                  ft_parse_length(const char *format, size_t *i, t_flag flag);
char                    *ft_hash(int power, t_flag flag);
int     	main(void);

#endif