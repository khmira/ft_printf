#include "ft_printf.h"
void    ft_printc(t_flags f, char c)
{
    while (f.dawidth > 1 && !f.daminus)
    {
        g_return_value += write(1," ",1);
        f.dawidth--;
    }
    g_return_value += write(1,&c,1);
    while (f.dawidth > 1 && f.daminus)
    {
        g_return_value += write(1," ",1);
        f.dawidth--;
    }
    
}
