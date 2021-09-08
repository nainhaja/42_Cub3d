/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:27:43 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/01 18:30:29 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pushv(void)
{
	float	v_x;
	float	v_y;

	v_x = g_p.x - g_vertical.x;
	v_y = g_p.y - g_vertical.y;
	g_sprite[g_sc].y = g_k * 64;
	g_sprite[g_sc].x = g_h * 64;
	g_sprite[g_sc].rotation = atan2(v_y, v_x);
	g_sprite[g_sc].ray_distance = sqrtf(powf((v_y), 2) + powf((v_x), 2));
	g_sprite[g_sc].xhalf = ((int)g_sprite[g_sc].x / 64 * 64) + 32;
	g_sprite[g_sc].yhalf = ((int)g_sprite[g_sc].y / 64 * 64) + 32;
	g_vertical.s_found = 1;
	g_sc++;
}

int		ft_increment_v(int *o)
{
	if (*o == 1)
	{
		*o = 0;
		return (0);
	}
	if ((g_vertical.y + g_vertical.ystep) / 64 > 0 &&
		(g_vertical.y + g_vertical.ystep) / 64 <= g_length_max)
	{
		g_vertical.x += g_vertical.xstep;
		g_vertical.y += g_vertical.ystep;
	}
	else
	{
		if ((g_vertical.y + g_vertical.ystep) / 64 < 0)
			g_vertical.y = 0;
		else if ((g_vertical.y + g_vertical.ystep) / 64 > g_length_max)
			g_vertical.y = (g_length_max + 1) * 64;
		return (0);
	}
	g_h = 0;
	g_k = 0;
	return (1);
}

int		ft_boucle(int *o)
{
	float new_x;

	if (g_vertical.xstep < 0)
		new_x = g_vertical.x - 64;
	else
		new_x = g_vertical.x;
	if (g_b[g_k][g_h] == '1' || g_b[g_k][g_h] == '2' || g_b[g_k][g_h] == '3')
	{
		if ((int)new_x / 64 == g_h && (int)(g_vertical.y) / 64 == g_k)
		{
			if (g_b[g_k][g_h] == '2')
				pushv();
			else
			{
				*o = 1;
				return (0);
			}
		}
	}
	return (1);
}

int		ft_checkv(void)
{
	int o;

	g_h = 0;
	g_k = 0;
	g_vertical.s_found = 0;
	while (1)
	{
		while (g_k < g_length_max)
		{
			while (ft_checkconditions(g_h, g_k))
			{
				if (!ft_boucle(&o))
					break ;
				g_h++;
			}
			g_h = 0;
			g_k++;
		}
		if (!ft_increment_v(&o))
			return (0);
	}
}
