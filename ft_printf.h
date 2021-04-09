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
int     ft_router(char *ptr);//renvoie selon % vers sa fonction appropriée
void    ft_printc();
void    ft_prints();
void    ft_printp();
void    ft_printd();
void    ft_printi();
void    ft_printd();
void    ft_printi();
void    ft_printu();
void    ft_printx();
void    ft_printX();
void    ft_collector(char *str);//collecte *.* pas besoin de collecter .
int     g_return_value
#endif
