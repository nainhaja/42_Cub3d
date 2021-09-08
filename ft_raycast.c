/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:16:36 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/02 11:18:30 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_mouvementt(void)
{
	if (g_p.rotationangle == 0)
	{
		g_horizontal.xstep = 0;
		g_vertical.ystep = 0;
		g_vertical.y = g_p.y - (g_p.x - g_vertical.x);
	}
	else
	{
		g_horizontal.xstep = g_horizontal.ystep / tan(g_p.rotationangle);
		g_vertical.ystep = (g_vertical.xstep * tan(g_p.rotationangle));
		g_vertical.y = g_p.y - (g_p.x - g_vertical.x) * tan(g_p.rotationangle);
	}
}

void	get_horizontal(void)
{
	if (sin(g_p.rotationangle) > 0)
	{
		g_horizontal.y = (int)(g_p.y / 64) * 64 + 64;
		g_horizontal.ystep = 64 * 1;
	}
	else
	{
		g_horizontal.y = floor(g_p.y / 64) * 64;
		g_horizontal.ystep = 64 * -1;
	}
	g_horizontal.x = ((g_horizontal.y - g_p.y + tan(g_p.rotationangle) *
				g_p.x) / tan(g_p.rotationangle));
}

void	get_vertical(void)
{
	if (cos(g_p.rotationangle) > 0)
	{
		g_vertical.x = (int)(g_p.x) / 64 * (64) + 64;
		g_vertical.xstep = 64 * 1;
	}
	else
	{
		g_vertical.x = (int)(g_p.x) / 64 * (64);
		g_vertical.xstep = 64 * -1;
	}
}

void	ft_raycast(void)
{
	get_horizontal();
	get_vertical();
	ft_player_mouvementt();
	ft_checkh();
	ft_checkv();
}
