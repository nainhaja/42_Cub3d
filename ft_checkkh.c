/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkkh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:20:38 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/01 18:20:45 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	push(void)
{
	float	h_x;
	float	h_y;

	h_x = g_p.x - g_horizontal.x;
	h_y = g_p.y - g_horizontal.y;
	g_sprite[g_sc].rotation = atan2(h_y, h_x);
	g_sprite[g_sc].ray_distance = sqrtf(powf((h_y), 2) + powf((h_x), 2));
	g_sprite[g_sc].y = g_k * 64;
	g_sprite[g_sc].x = g_h * 64;
	g_sprite[g_sc].xhalf = ((int)g_sprite[g_sc].x / 64 * 64) + 32;
	g_sprite[g_sc].yhalf = ((int)g_sprite[g_sc].y / 64 * 64) + 32;
	g_sc++;
	g_horizontal.s_found = 1;
}

int		ft_increment_h(int *po)
{
	if (*po == 2)
	{
		*po = 0;
		return (0);
	}
	if ((int)(g_horizontal.y + g_horizontal.ystep) / 64 >= 0 &&
		(int)(g_horizontal.x + g_horizontal.xstep) / 64 >= 0 &&
		(g_horizontal.x + g_horizontal.xstep) / 64 <= g_width_max)
	{
		g_horizontal.x += g_horizontal.xstep;
		g_horizontal.y += g_horizontal.ystep;
	}
	else
	{
		if ((g_horizontal.x + g_horizontal.xstep) / 64 >= g_width_max)
			g_horizontal.x = g_width_max * 64;
		else if (g_horizontal.x + g_horizontal.xstep <= 0)
			g_horizontal.x = 0;
		return (0);
	}
	g_h = 0;
	g_k = 0;
	return (1);
}

int		ft_boucle_h(int *po)
{
	float new_y;

	if (g_horizontal.ystep < 0)
		new_y = g_horizontal.y - 64;
	else
		new_y = g_horizontal.y;
	if (g_b[g_k][g_h] == '1' || g_b[g_k][g_h] == '2' || g_b[g_k][g_h] == '3')
	{
		if ((int)(g_horizontal.x) / 64 == g_h && (int)new_y / 64 == g_k)
		{
			if (g_b[g_k][g_h] == '2')
				push();
			else
			{
				*po = 2;
				return (0);
			}
		}
	}
	return (1);
}

int		ft_checkh(void)
{
	int po;

	g_horizontal.s_found = 0;
	g_h = 0;
	g_k = 0;
	while (1)
	{
		while (g_k < g_length_max)
		{
			while (ft_checkconditions(g_h, g_k))
			{
				if (!ft_boucle_h(&po))
					break ;
				g_h++;
			}
			g_h = 0;
			g_k++;
		}
		if (!ft_increment_h(&po))
			return (0);
	}
}
