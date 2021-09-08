/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawsprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:35:07 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/02 10:41:19 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_null(float xprime, float yprime, int sprc, float dis_angle)
{
	double	diso;
	float	dis_x;
	float	dis_y;

	dis_x = g_sprite[sprc].xhalf + (32 * cos(dis_angle));
	dis_y = g_sprite[sprc].yhalf + (32 * sin(dis_angle));
	g_sprite[sprc].xoff = sqrtf(powf(xprime - dis_x, 2) +
							powf(yprime - dis_y, 2));
	diso = sqrtf(powf(xprime - g_sprite[sprc].xhalf, 2) +
			powf(yprime - g_sprite[sprc].yhalf, 2));
	if (diso > 30)
		g_sprite[sprc].xoff = 0;
}

void	find_point(int sprc)
{
	float	a;
	float	b;
	float	xprime;
	float	yprime;
	float	dis_angle;

	b = atan2(g_p.y - g_sprite[sprc].yhalf,
		g_p.x - g_sprite[sprc].xhalf);
	a = ((g_sprite[sprc].rotation - b));
	xprime = g_p.x + (g_sprite[sprc].xhalf - g_p.x) * cos(a)
			- (g_sprite[sprc].yhalf - g_p.y) * sin(a);
	yprime = g_p.y + (g_sprite[sprc].xhalf - g_p.x) * sin(a)
			+ (g_sprite[sprc].yhalf - g_p.y) * cos(a);
	dis_angle = b - (M_PI / 2);
	ft_check_null(xprime, yprime, sprc, dis_angle);
}

void	ft_calculate(float *w_ht, double *start, int sprc)
{
	double ray_distance;

	ray_distance = sqrtf(powf((g_p.y - g_sprite[sprc].yhalf), 2)
					+ powf((g_p.x - g_sprite[sprc].xhalf), 2));
	*w_ht = (64 / ray_distance) * ((g_width / 2) / tan(RAD(30)));
	*start = (g_length / 2) - (*w_ht / 2) + 1;
	if (*start < 0)
		*start = 0;
}

void	ft_store_dataa(float w_ht, int *mhah, int sprc)
{
	int				distancefromtop;
	int				yoff;
	unsigned int	col;

	distancefromtop = *mhah + (w_ht / 2) - (g_length / 2);
	yoff = distancefromtop * (float)64 / w_ht;
	col = g_spritee.tex_data[(64 * yoff) + (int)g_sprite[sprc].xoff];
	if (col != 0x000000)
		g_img_data[(int)*mhah * g_width + g_ray_count] = col;
	*mhah = *mhah + 1;
}

void	ft_draw_sprite_column(int sprc)
{
	float	w_ht;
	double	start;
	double	end;
	int		mhah;

	ft_calculate(&w_ht, &start, sprc);
	end = (g_length / 2) + (w_ht / 2);
	mhah = start;
	find_point(sprc);
	while (mhah < end && mhah < g_length)
		ft_store_dataa(w_ht, &mhah, sprc);
}
