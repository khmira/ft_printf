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
/*	if (nb < 0)
	{
		ft_putchar('-');
		q = -nb;
	}
	else*/
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
/*	if (nb < 0)
	{
		ft_putchar('-');
		q = -nb;
	}
	else*/
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
	if (data->w < 0)
		data->w--;
	int d = va_arg(args, int);
	data->w -=  ft_strlenD(d);
	while (data->w  > 0)
	{
		ft_putchar(' ');
		data->w--;
	}
	ft_putnbr(d);
}
void	get_type(const char **text, va_list args, t_data *data)
{
	int t = 0;
	t = wANDp(args, text, data);

	if (**text == 'd' && (*text)++)
	{
		type_width_for_d(data,args);
		//ft_putnbr(va_arg(args, int));
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
			//get_type(&(text) + wANDp(args, &text, intdata), args);
			get_type(&text, args, &data);
	
		else {
			ft_putchar(*text);
			text++;
		
		}
	}
//	printf("minus: %d\nwANDp: %d\nprec: %d\nwidth: %d\nminus: %d\nzero: %d\n",data.m, t,data.p, data.w, data.m, data.z);
	va_end(args);
}
int	main()
{
	//char *k = "a%dqwerty%di\n%d%d%di%d";
	//print(k,1, 2);
//	print("%d%#%s$%#%s\n",1, "qwerty","qwerty");
	char e = 'k';

//	print("-*.*c\n",123,456, e);
	printf("printf:\n%*d<-\n",15, 123);
	printf("%15d<-\n", 123);
	print("print:\n%*d<-\n",15, 123);
	print("%15d<-\n", 123);
	printf("printf:\n%5d<-\n", 123);
	print("print: \n%5d<-\n", 123);

//	print("##");
	return (0);
}
