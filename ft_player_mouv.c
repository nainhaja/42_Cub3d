/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_mouv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:10:17 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/02 11:11:43 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_initialise(void)
{
	float s;

	s = -30;
	g_ray_count = 0;
	g_p.rotationangle -= RAD(30);
	g_sprite = (t_imgptr*)malloc(sizeof(t_imgptr) * ft_countsprites());
	return (s);
}

void	ft_player_mouvement(float *s)
{
	g_p.rotationangle -= g_p.turndirection *
						(60 / (float)g_width) * (M_PI / 4);
	if (g_p.rotationangle < 0)
		g_p.rotationangle = 2 * M_PI + g_p.rotationangle;
	g_p.x += ((cos(g_p.rotationangle + g_rotation)) * 4 * g_p.walkdirection);
	g_p.y += ((sin(g_p.rotationangle + g_rotation)) * 4 * g_p.walkdirection);
	ft_collision();
	g_theta = g_p.rotationangle;
	*s = ft_initialise();
}
