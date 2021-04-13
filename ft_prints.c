#include "ft_printf.h"

static int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);    
}
void    ft_prints(t_flags f, char *s)
{
    int len;

    if (!s)
        s = "(null)";
    len = ft_strlen(s);
    if ((f.preci > len) || (f.preci < 0))
        f.preci = len;
    f.dawidth -= f.preci;
    if (f.dawidth < 0)
        f.dawidth = 0;
    while (f.dawidth > 0 && !f.daminus)
    {
        g_return_value += write(1," ",1);
        f.dawidth--;
    }
    g_return_value += write(1,s,f.preci);
    while (f.dawidth > 0 && f.daminus)
    {
        g_return_value += write(1," ",1);
        f.dawidth--;
    }
}
