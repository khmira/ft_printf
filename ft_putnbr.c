#include "ft_printf.h"

void    ft_putnbr(long n, int base, char *tab)
{
    if (n < 0)
		n *= -1;
    if (n > base)
        ft_putnbr(n / base, base, tab);
    g_return_value += write(1,&tab[n%base],1);
}