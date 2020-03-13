#include "ft_printf.h"
#include <stdio.h>

typedef	struct	s_data
{
	int p;
	int w;
	int m;
	int z;
}				t_data;
void	deTOhex(size_t   nb)
{
	long int r;
	unsigned  long int q;
	int i;
	int j;
	int temp;
	char h[1000000];

	i = 1;
		q = nb;
	while (q) {
		temp = q % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55 + 32;
		h[i++] = temp;
		q = q / 16;
		j = i - 1;
	}
	while (j)
	{
		ft_putchar(h[j]);
		j--;
	}	
}
void	deTOheX(size_t   nb)
{
	long int r;
	unsigned  long int q;
	int i;
	int j;
	int temp;
	char h[1000000];

	i = 1;
		q = nb;
	while (q) {
		temp = q % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		h[i++] = temp;
		q = q / 16;
		j = i - 1;
	}
	while (j)
	{
		ft_putchar(h[j]);
		j--;
	}	
}

void	initialize(t_data *data)
{
	data->p = 0;
	data->w = 0;
	data->m = 0;
	data->z = 0;
}
int		wANDp(va_list args, const char **text, t_data *data)
{
	int i;

	i = 0;
	if(**text == '-')
	{
		data->m = 1;
		(*text)++;
		i++;
	}
	else if(**text == '0')
	{
		data->z = 1;
		(*text)++;
		i++;
	}
	if(ft_isdigit(**text)){
		data->w = ft_atoi((char *)*text);
		while (ft_isdigit(**text))
		{
			(*text)++;
			i++;
		}
	}
	else if(**text == '*')
	{
		data->w = va_arg(args, int);
		(*text)++;
		i++;
	}
	if (**text == '.')
	{
		(*text)++;
		i++;
		if(ft_isdigit(**text)){
			data->p = ft_atoi((char *)*text);
			while (ft_isdigit(**text))
			{
				(*text)++;
				i++;
			}
		}
		else if(**text == '*')
		{
			data->p = va_arg(args, int);
			(*text)++;
			i++;
		}
	}
	return (i);
}	
void	type_width_for_c(t_data *data)
{
	if (data->w < 0)
		data->w--;
	while (data->w)
	{
		ft_putchar(' ');
		data->w--;
	}
}
void	type_width_for_d(t_data *data, va_list args)
{
	if (data->p < 0)
	{
		data->p = 0;
	}
	int d = va_arg(args, int);

	int c =  data->p - ft_strlenD(d);	
	if (c < 0)
		c = 0;

	if (data->w < 0)
		data->w--;
	if (data->m == 0) {
			int ci;
		if (c != 0)
		 ci = data->w - c - ft_strlenD(d);
		else ci = data->w  - ft_strlenD(d);
		while (ci  > 0)
		{
			ft_putchar(' ');
			ci--;
		}
	while (c > 0)
	{
		ft_putnbr(0);
		c--;
	}
	ft_putnbr(d);
	}
	else if (data->m == 1)
	{
			int ci;
		if (c != 0)
		 ci = data->w - c;
		else ci = data->w  - ft_strlenD(d);
		

		while (ci--  > 0)
		{
			ft_putchar(' ');
		}
		while (c--)
			ft_putnbr(0);
		ft_putnbr(d);

	}
	initialize(data);
}

void	get_type(const char **text, va_list args, t_data *data)
{
	int t = 0;
	t = wANDp(args, text, data);

	if (**text == 'd' && (*text)++)
	{
		type_width_for_d(data,args);
	}
	else if (**text == 'u' && (*text)++)
		ft_putnbrU(va_arg(args,unsigned int));

	else if (**text == 's' && *text++)
		ft_putstr(va_arg(args, char *));
	else if (**text == 'x' && *text++)
		deTOhex(va_arg(args, unsigned int));	
	else if (**text == 'X' && *text++)
		deTOheX(va_arg(args, unsigned int));

	else if (**(text ) == 'c' && *text++)
	{
		type_width_for_c(data);
		ft_putchar(va_arg(args, int));
	}
	else if (**text == 'p' && *text++)
	{
		ft_putstr("0x");
		deTOhex((size_t)va_arg(args, void *));
	}
}

void	print(const char *text, ...)
{
	va_list args;
	int i;
	int min;
	t_data data;

	va_start(args, text);
	initialize(&data);
	int t = wANDp(args, &text, &data);

	while (*text)
	{
		if (*text == '%' && text++)
		{
			get_type(&text, args, &data);
		}
	
		else {
			ft_putchar(*text);
			text++;
		
		}
	}
	va_end(args);
}
int	main()
{
	char e = 'k';

	setbuf(stdout, NULL);
	printf("%15.12d%c<-\n", 123456789, e);
	print("%15.12d%c<-\n", 123456789, e);
	return (0);
}
