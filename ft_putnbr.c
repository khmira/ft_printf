/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:19:27 by abadidi           #+#    #+#             */
/*   Updated: 2020/02/21 22:01:42 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void	ft_putchar(char c);
#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	unsigned int my_nb;

	if (nb < 0)
	{
		ft_putchar('-');
		my_nb = -nb;
	}
	else
		my_nb = nb;
	if (my_nb / 10 != 0)
		ft_putnbr(my_nb / 10);
	ft_putchar(my_nb % 10 + '0');
}
