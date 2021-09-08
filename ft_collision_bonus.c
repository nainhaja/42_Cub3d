/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 02:23:36 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/15 02:23:45 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_collision(void)
{
	g_h = 0;
	g_k = 0;
	while (g_k < g_length_max)
	{
		while (ft_checkconditionss())
		{
			if (g_b[g_k][g_h] == '1' || g_b[g_k][g_h] == '2')
			{
				if ((int)g_p.x / 64 == g_h && (int)g_p.y / 64 == g_k)
				{
					g_p.x -= (cos(g_p.rotationangle + g_rotation))
							* 4 * g_p.walkdirection;
					g_p.y -= (sin(g_p.rotationangle + g_rotation))
							* 4 * g_p.walkdirection;
				}
			}
			g_h++;
		}
		g_h = 0;
		g_k++;
	}
	g_k = 0;
	g_h = 0;
}
