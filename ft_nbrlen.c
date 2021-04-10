#include "ft_printf.h"

int     ft_nrblen(long nbr, int base) 
{
	int	i;

	i = 1;
	while (nbr /= base)
		i++;
	return (i);
}
