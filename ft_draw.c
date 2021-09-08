/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:03:28 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/01 20:03:59 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_color(void)
{
	int color;

	color = 0;
	if (g_b[g_k][g_h] == '0')
		color = 0xFFFFFF;
	else if (g_b[g_k][g_h] == '2')
		color = 0x4b2F50;
	else if (g_b[g_k][g_h] == '1')
		color = 0x6497b1;
	else if (g_b[g_k][g_h] == '3')
		color = 0x6497b1;
	else if (ft_check_direction(g_b[g_k][g_h]) == 1)
		color = 0xFFFFFF;
	return (color);
}

int		ft_print_square(int cpt1, int color, int *i, int j)
{
	while (j < cpt1)
	{
		ft_pixel_put(g_img_data, *i, j, color);
		j++;
	}
	j = j - 64;
	*i = *i + 1;
	return (j);
}

void	ft_update_data(int *i, int *j, int *cpt1, int *cpt)
{
	*i = 0;
	*j = *j + 64;
	*cpt = 64;
	*cpt1 = *cpt1 + 64;
	g_k++;
	g_h = 0;
}

void	ft_draw(void)
{
	int color;
	int i;
	int j;
	int cpt;
	int cpt1;

	i = 0;
	j = 0;
	cpt = 0;
	cpt1 = 64;
	while (g_k < g_length_max)
	{
		while (ft_checkconditions(g_h, g_k))
		{
			color = ft_get_color();
			while (i < cpt)
				j = ft_print_square(cpt1, color, &i, j);
			cpt = cpt + 64;
			g_h++;
		}
		ft_update_data(&i, &j, &cpt1, &cpt);
	}
	g_k = 0;
}
