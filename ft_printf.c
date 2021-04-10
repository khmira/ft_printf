#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	va_start (ap, str);
	g_return_value = 0; //compteur
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			ft_collector(ap, (char **)(&str));
		}
		g_return_value += write(1, str, 1); // unistd.h
		str++;
	}
	va_end (ap);
	return (g_return_value);
}
