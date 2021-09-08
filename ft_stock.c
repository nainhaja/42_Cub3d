/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:33:59 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/02 11:35:25 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_direction(char dir)
{
	if (dir == 'N')
		g_p.rotationangle = (M_PI / 2);
	else if (dir == 'S')
		g_p.rotationangle = (-M_PI / 2);
	else if (dir == 'E')
		g_p.rotationangle = 0;
	else if (dir == 'W')
		g_p.rotationangle = M_PI;
	g_p.found++;
}

int		ft_cond(int mi, char *stock, int ab)
{
	if (stock[mi] == ' ' || stock[mi] == '2' || stock[mi] == '1' ||
		ft_check_direction(stock[mi]) == 1 || stock[mi] == 0 ||
		stock[mi] == '0' || stock[mi] == '3')
	{
		g_m[g_a][ab] = stock[mi];
		if (ft_check_direction(g_m[g_a][ab]) == 1)
		{
			g_p.x = ab * 64;
			g_p.y = g_a * 64;
			ft_get_direction(g_m[g_a][ab]);
		}
		return (1);
	}
	return (0);
}

int		ft_checkfirstline(int ab, int c)
{
	int toto;

	toto = 0;
	if (g_a == 0)
	{
		while (g_m[g_a][toto] == '1')
			toto++;
		if (toto != ab)
			return (1);
	}
	ab = 0;
	if (c == 0)
		g_a++;
	else
		g_m[g_a + 1] = 0;
	return (0);
}

int		ft_size(char *stock)
{
	int mi;

	mi = 0;
	while (stock[mi] != '\0')
		mi++;
	return (mi + 1);
}

int		ft_stock(char *stock, char *t, int c)
{
	int	mi;
	int	mj;
	int	ab;

	mi = 0;
	mj = 0;
	ab = 0;
	stock = t;
	g_m[g_a] = malloc(sizeof(char) * ft_size(stock));
	ft_check_player(stock, t, c);
	while (stock[mi] != '\0')
	{
		if (ft_cond(mi, stock, ab))
		{
			mi++;
			ab++;
		}
		else
		{
			ft_putstr("Error wrong mapp");
			exit(0);
		}
	}
	g_m[g_a][ab] = ft_get_length(ab);
	return (ft_checkfirstline(ab, c));
}
