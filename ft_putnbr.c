/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 01:54:49 by nainhaja          #+#    #+#             */
/*   Updated: 2019/07/10 05:18:37 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr2(unsigned int a)
{
	if (a <= 9)
		ft_putchar(((char)a) + '0');
	else
	{
		ft_putnbr2(a / 10);
		ft_putnbr2(a % 10);
	}
}

void	ft_putnbr(int a)
{
	if (a < 0)
	{
		ft_putchar('-');
		ft_putnbr2(-a);
	}
	else
		ft_putnbr2(a);
}
