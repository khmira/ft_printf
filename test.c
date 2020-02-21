#include "ft_printf.h"
//void	print(
int	main()
{
	char *k = "qwertyi%d";
	while (*k)
	{
		if (*k != '%')
		{
			ft_putchar(*k);
//			k++;
		}
		k++;
	}
	return (0);
}
