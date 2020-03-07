#include "ft_printf.h"

void	ft_putnbrU(unsigned int nb)
{
	unsigned int my_nb;

	my_nb = nb;
	if (my_nb / 10 != 0)
		ft_putnbr(my_nb / 10);
	ft_putchar(my_nb % 10 + '0');
}
