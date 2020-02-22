#include "ft_printf.h"
#include <stdio.h>

int	add(int args, ...)
{
	va_list ap;

	va_start(ap, args);
	int i = args;
	int sum = args;
	while (i--)
	{
		sum += va_arg(ap, int);
	}

	va_end(ap);
	return (sum);
}
void	until0(int first, ...)
{
	va_list list;
	va_start(list, first);
	int num = first;
	while (num)
	{
		printf("%d\n", num);
		num = va_arg(list, int);
	}
	va_end(list);
}
void	print(char *text, ...)
{
	va_list args;

	va_start(args, text);
	while (*text)
	{
		if (*text != '%')
		{
			ft_putchar(*text);
			text++;
		}
		else if (*text == '%' && *(text + 1) == 'd')
		{
			ft_putnbr(va_arg(args, int));
			text = text + 2;
		}
	}
}
int	main()
{
	char *k = "";
	print("2%dqwerty%di",1);
	return (0);
}
