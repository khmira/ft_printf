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
void	get_type(const char **text, va_list args)
{
	if (**text == 'd' && *text++)
		ft_putnbr(va_arg(args, int));
	if(**text == 's' && *text++)
		ft_putstr(va_arg(args, char *));
}

void	print(const char *text, ...)
{
	va_list args;

	va_start(args, text);
	while (*text)
	{
		if (*text == '%' && text++)
			get_type(&text, args);
		else
			ft_putchar(*text);
		text++;
	}
	va_end(args);
}
int	main()
{
	//char *k = "a%dqwerty%di\n%d%d%di%d";
	//printf(k,1, 2);
	print("d#%s#%s", "qwerty","qwerty");
//	printf(k, 1,2,3,4,5,6);
//	print("##");
	return (0);
}
