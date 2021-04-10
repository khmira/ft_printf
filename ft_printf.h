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
size_t  ft_strlen(char *str);
int     ft_nrblen(long nbr, int base); // base : possibilité de changer de base pour nbr
int     ft_router(char ptr, t_flags f, va_list ap);//renvoie selon % vers sa fonction appropriée
void    ft_printc(t_flags f, char c);
void    ft_prints(t_flags f, char *s);
void    ft_printp(t_flags f, size_t p);
void    ft_printd(t_flags f, long d);
void    ft_printu(t_flags f, unsigned int u);
void    ft_printx(t_flags f, unsigned u);
void    ft_printX(t_flags f, unsigned u);
void    ft_collector(va_list ap, char **str);
void    ft_putnbr(long n, int base, char *tab);
int     g_return_value;

#endif
