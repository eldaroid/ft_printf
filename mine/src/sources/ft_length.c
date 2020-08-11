#include "../header/ft_printf.h"

long long int		ft_length_int(va_list list, t_flag flag)
{
	long long int	nbr;

	nbr = va_arg(list, long long int);
	if (flag.length.ll == 1)
		nbr = (long long int)nbr;
	else if (flag.length.l == 1)
		nbr = (long int)nbr;
	else if (flag.length.h == 1)
		nbr = (short int)nbr;
	else if (flag.length.hh == 1)
		nbr = (char)nbr;
	return (nbr);
}

unsigned long long int		ft_length_uint(va_list list, t_flag flag)
{
	unsigned long long int	nbr;

	nbr = va_arg(list, unsigned long long int);
	if (flag.length.hh == 1)
		nbr = (unsigned char)nbr;
	else if (flag.length.h == 1 && flag.type != 'U')
		nbr = (unsigned short int)nbr;
	else if (flag.length.l == 1)
		nbr = (unsigned long int)nbr;
	else if (flag.length.ll == 1)
		nbr = (unsigned long long int)nbr;
	return (nbr);
}