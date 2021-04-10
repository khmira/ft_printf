#include "ft_printf.h"

void    ft_collector(va_list ap, char **str)
{
	t_flags f;

	f.dawidth = 0;
	f.preci = -1;
	f.zero = 0;
	f.daminus = 0;
	while (**str== '-')
	{
		f.daminus = 1;
		(*str)++;
	}
	while (**str== '0')
	{
		f.zero = 1;
		(*str)++;
	}
	if (**str== '*')
	{
		f.dawidth =  va_arg(ap, int); // récupere width de va_arg il est int
		if (f.dawidth < 0)
		{
			f.dawidth*= (-1);
			f.daminus = 1;
		}
		(*str)++;
	}
	else
	{

		while (**str >= '0' && **str <= '9') // à mettre dans le else de *
		{
			f.dawidth = f.dawidth * 10 + **str - 48;
			(*str)++;
		}// ce while est au lieu de atoi
	}
	if (**str == '.')
	{
		(*str)++;
		f.preci = 0; 
		if (**str== '*')
		{
			f.preci =  va_arg(ap, int); // récupere width de va_arg il est int
			if (f.preci < 0)
				f.preci = 0;
			(*str)++;
		}
		else
	{

		while (**str >= '0' && **str <= '9') // à mettre dans le else de *
		{
			f.preci = f.preci * 10 + **str - 48;
			(*str)++;
			}// ce while est au lieu de atoi

	}
	}
	ft_router(**str, f, ap);
	(*str)++;
	//printf("width = %d\nprec = %d\nzero = %d\nminus =%d\n",(int)f.dawidth,f.preci,f.zero,f.daminus);
}
