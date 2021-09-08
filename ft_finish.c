/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:03:42 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/02 11:04:29 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wall_coordinates(void)
{
	int hvhit;

	hvhit = 0;
	if (g_horizontal.distance < g_vertical.distance)
	{
		g_wall.dis = g_horizontal.distance;
		g_wall.x = g_horizontal.x;
		g_wall.y = g_horizontal.y;
		hvhit = 1;
	}
	else
	{
		g_wall.x = g_vertical.x;
		g_wall.y = g_vertical.y;
		g_wall.dis = g_vertical.distance;
		hvhit = 2;
	}
	return (hvhit);
}

int	ft_grr(void)
{
	int sprc;

	g_horizontal.distance = sqrtf(powf((g_p.y - g_horizontal.y), 2) +
							powf((g_p.x - g_horizontal.x), 2));
	g_vertical.distance = sqrtf(powf((g_p.y - g_vertical.y), 2) +
							powf((g_p.x - g_vertical.x), 2));
	ft_draw_column(get_wall_coordinates());
	if (g_vertical.s_found == 1 || g_horizontal.s_found == 1)
	{
		if (g_vertical.s_found == 1 && g_horizontal.s_found == 1)
			sorting_sprites();
		sprc = g_sc - 1;
		while (sprc >= 0)
		{
			if (g_sprite[sprc].ray_distance < g_wall.dis)
				ft_draw_sprite_column(sprc);
			sprc--;
		}
	}
	g_horizontal.s_found = 0;
	g_vertical.s_found = 0;
	g_ray_count++;
	return (0);
}
