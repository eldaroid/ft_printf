/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:38:33 by fgracefo          #+#    #+#             */
/*   Updated: 2020/08/14 15:00:22 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#	include <stdarg.h>
#	include <stdio.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <float.h>

typedef struct s_length
{
    int     ll;
    int     hh;
    int     l;
    int     h;
	int		L;
	int		minus;
}           t_length;

typedef struct	s_size
{
	int			star;
	int			zero;
	int			plus;
	int			space;
	int			dot;
}				t_size;

// star - !'-'!, '+', !'weight'!, ?'#'?, !'*'!

typedef struct	s_flag
{
	int			star;
	int			zero;
	int			plus;
	int			space;
	int			dot;
	int			minus_plus;
	int			hash;
	int			type;
	t_length	length;
	t_size		size;
}				t_flag;

int     	ft_printf(const char *format, ...);
int			print_type(const char *str, size_t *i, va_list list, t_flag flag);
int     	ft_count_size(const char *format, size_t *i, va_list list);
t_flag	ft_parse_zero(const char *format, size_t *i, va_list list, t_flag flag);
t_flag  	ft_parse_flag(const char *format, size_t *i, va_list list, t_flag flag);
int     	ft_parser(const char *format, size_t *i, va_list list);
int			ft_atoi_minus_star(size_t *i, va_list list, int sign);
int    		ft_sprintf(const char *format, va_list list);
t_flag	ft_parse_plus(const char *format, size_t *i, va_list list, t_flag flag);
t_flag	ft_parse_dot(const char *format, size_t *i, va_list list, t_flag flag);
t_flag	ft_parse_space(const char *format, size_t *i, va_list list, t_flag flag);
t_flag	ft_parse_minus(const char *format, size_t *i, va_list list, t_flag flag);
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
int			ft_print_unsint(va_list list,
			t_flag flag, int base, int is_toupper);
int			ft_power(long long n, int base);
char		ft_symbol(int n);
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, char c, int n);
int			ft_toupper(int c);
char		*ft_strdup(const char *src);
int		ft_print_with_indent(char *str, int size_star, int str_len, int clean);
char		*ft_itoa_base(long long n, int base, t_flag flag);
char		*ft_itoa_addres(unsigned long long n, t_flag flag);
char		*ft_itoa(int n);
int			division_by_type(int type, va_list list, t_flag flag, int count);
int			size_flags(t_flag flag, int	k);
int			ft_print_float(va_list list,t_flag flag);
char		*ft_before_dot(double number, int check_dot, t_flag flag, int zero);
char			*ft_after_dot(long double nb, int weight);
char		*ft_strjoin(char const *s1, char const *s2);
int			check_size(t_flag flag);
// void		*reverse_array(char *str);
long double	rounding(long double nb, int precision, int sign);
char		*ft_string_float(double nb, t_flag flag);
int     	is_double_negative(double nb);
unsigned long long int	ft_length_uint(va_list list, t_flag flag);
long long int			ft_lenint(va_list list, t_flag flag);
t_flag      ft_parse_len(const char *format, size_t *i, va_list list, t_flag  flag);
char     	*ft_hash(int power, t_flag flag);
int			ft_printint(char *str, int size_star, int str_len, t_flag flag);
char		*ft_utoa_base(unsigned long long int n, int base, t_flag flag);
int			ft_upower(unsigned long long int n, int base);
int     	ft_sprintf(const char *format, va_list list);
int		check_all(const char *format, size_t *i, va_list list, int count);
int     	main(void);
void	hashing(char type, char **str, int power);
char	*string_of_float(double nb, int precision, int str_after, t_flag flag);
int	division_next(int type, va_list list, t_flag flag, int count);
int			check_len(int len, t_flag flag, char *str);
int			print_zero(int k, int len, int zero);
int		check_count(int size_star, int str_len);
void	ft_free(int clean, char *str);
int			check_flag_size(t_flag flag, long long int i, int str_len);
int			check_strlen(t_flag flag, char *str, int str_len, long long int i);
int			ft_check_power(t_flag flag, unsigned long long int n, int base);
int			check_power(t_flag flag, long long n, int base, int sign);
int					new_star(t_flag flag, int len);
char	*new_string(t_flag flag, int base, va_list list);
int					check_undefine(t_flag flag);
char	*ft_bef(long double number, int check_dot, t_flag flag, int zero);
long double	long_rounding(long double nb, int precision, int sign);
char		*string_long(long double nb, int precision,
						int str_after, t_flag flag);
char		*ft_long_float(long double nb, t_flag flag);
int		new_flag_star(t_flag flag, long double number, long long str_len);
long long int check_my_strlen(t_flag flag, long double number, long long str_len, char *str);
char		*ft_after_long(long double nb, int weight);

#endif