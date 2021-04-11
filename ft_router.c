#include "ft_printf.h"

int     ft_router(char ptr, t_flags f, va_list ap) // ptr = form identifier
{
    if (ptr == 'c')
        ft_printc(f, va_arg(ap, int));
    if (ptr == 's')
        ft_prints(f, va_arg(ap, char *));
    if (ptr == 'd' || ptr == 'i')
        ft_printdiu(f, va_arg(ap, int));
    if (ptr == 'x')
        ft_printx(f, va_arg(ap, unsigned));
    if (ptr == 'X')
        ft_printX(f, va_arg(ap, unsigned));
    if (ptr == 'p')
        ft_printp(f, va_arg(ap, size_t));
    if (ptr == 'u')
        ft_printdiu(f, va_arg(ap, unsigned));
    if (ptr == '%')
        ft_printc(f, '%');
    return 0;
}
