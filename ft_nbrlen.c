#include "ft_printf.h"

int     ft_nrblen(long long nbr, int base) 
{
	int	i;

	i = 1;
	while (nbr /= base)
		i++;
	return (i);
}
