#include "ft_printf.h"

void    ft_printd(t_flags f, long d)
{
    int len;

    len = ft_nrblen(d, 10);
    
    if (f.preci >= 0)
    {
        f.preci -= len;
        (f.preci < 0) && (f.preci = 0);
    }
    (f.dawidth) && (f.dawidth -= (len + f.preci));
    (d < 0) && (f.dawidth--);
    (f.dawidth < 0) && (f.dawidth = 0);
    while (f.dawidth > 0)
    {
        if (f.zero)
            g_return_value += write(1,"0",1);
        else
            g_return_value += write(1," ",1);
        f.dawidth--;
    }
    if (d < 0)
        g_return_value += write(1,"-",1);
    while (f.preci > 0)
    {
        g_return_value += write(1,"0",1);
        f.preci--;
    }
    ft_putnbr(d, 10, "0123456789");
}
