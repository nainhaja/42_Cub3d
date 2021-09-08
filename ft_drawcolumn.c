/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawColumn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:39:17 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/02 09:50:58 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	check_dir(unsigned int col, int hvhit, int yoff, int xoff)
{
	if (hvhit == 1)
	{
		if (sin(g_p.rotationangle) > 0)
			col = g_no.tex_data[(64 * yoff) + xoff];
		else
			col = g_so.tex_data[(64 * yoff) + xoff];
	}
	else if (hvhit == 2)
	{
		if (cos(g_p.rotationangle) > 0)
			col = g_ea.tex_data[(64 * yoff) + xoff];
		else
			col = g_we.tex_data[(64 * yoff) + xoff];
	}
	return (col);
}

void			ft_draw_floor(double start, double g_length, int mhah)
{
	int ayoub;

	ayoub = 0;
	while (ayoub < start)
	{
		g_img_data[(int)ayoub * g_width + g_ray_count] = g_f_colour;
		ayoub++;
	}
	while (mhah < g_length)
	{
		g_img_data[(int)mhah * g_width + g_ray_count] = g_c_colour;
		mhah++;
	}
}

int				ft_prepare(int hvhit)
{
	int	xoff;
	int	t_y;

	t_y = 0;
	xoff = 0;
	while (t_y < g_length)
		g_img_data[t_y++ * g_width + g_ray_count] = 0;
	if (hvhit == 1)
		xoff = (int)g_horizontal.x % 64;
	else if (hvhit == 2)
		xoff = (int)g_vertical.y % 64;
	return (xoff);
}

void			store(int mhah, double wall_height, int xoff, int hvhit)
{
	int				distancefromtop;
	int				yoff;
	unsigned int	col;

	distancefromtop = mhah + (wall_height / 2) - (g_length / 2);
	yoff = distancefromtop * (float)64 / wall_height;
	col = 0;
	col = check_dir(col, hvhit, yoff, xoff);
	g_img_data[(int)mhah * g_width + g_ray_count] = col;
}

void			ft_draw_column(int hvhit)
{
	double	wall_height;
	double	start;
	double	end;
	int		xoff;
	int		mhah;

	wall_height = (64 / (g_wall.dis * cos(g_theta - g_p.rotationangle)))
				* ((g_width / 2) / tan(RAD(30)));
	start = (g_length / 2) - (wall_height / 2) + 1;
	if (start < 0)
		start = 0;
	end = (g_length / 2) + (wall_height / 2);
	xoff = ft_prepare(hvhit);
	mhah = start;
	while (mhah < end && mhah < g_length)
	{
		store(mhah, wall_height, xoff, hvhit);
		mhah++;
	}
	ft_draw_floor(start, g_length, mhah);
}
