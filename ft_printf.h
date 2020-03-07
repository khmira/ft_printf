#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putnbrU(unsigned int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
#endif
