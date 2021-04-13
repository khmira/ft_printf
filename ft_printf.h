#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
typedef struct s_flags {
    long dawidth;
    int preci;
    int zero;
    int daminus;
    int star;
}               t_flags;

int     ft_printf(const char *, ...);
int     ft_nrblen(long long nbr, int base); // base : possibilité de changer de base pour nbr
int     ft_router(char ptr, t_flags f, va_list ap);//renvoie selon % vers sa fonction appropriée
void    ft_printc(t_flags f, char c);
void    ft_prints(t_flags f, char *s);
void    ft_printp(t_flags f, long long d);
void    ft_printdiu(t_flags f, long long d);
void    ft_printx(t_flags f, long long d);
void    ft_printX(t_flags f, long long d);
void    ft_collector(va_list ap, char **str);
void    ft_putnbr(long long n, int base, char *tab);
int     g_return_value;

#endif