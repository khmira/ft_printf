#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	unsigned int my_nb;

	if (nb < 0)
	{
		ft_putchar('-');
		my_nb = -nb;
	}
	else
		my_nb = nb;
	if (my_nb / 10 != 0)
		ft_putnbr(my_nb / 10);
	ft_putchar(my_nb % 10 + '0');
}
