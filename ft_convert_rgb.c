/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:58:23 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/01 19:59:39 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		convertrgbtoint(int r, int g, int b)
{
	int hexcode;

	if ((r >= 0 && r <= 255)
		&& (g >= 0 && g <= 255)
		&& (b >= 0 && b <= 255))
	{
		hexcode = (r * 65536) + (g * 256) + b;
		return (hexcode);
	}
	else
		return (0);
}

int		converthextor(int rgb)
{
	int r;

	r = rgb >> 16;
	return (r);
}

int		converthextog(int rgb)
{
	int g;

	g = (rgb & 0x00ff00) >> 8;
	return (g);
}

int		converthextob(int rgb)
{
	int b;

	b = (rgb & 0x0000ff);
	return (b);
}

int		ft_check_sol(char *t)
{
	int		r;
	int		g;
	int		b;
	char	**det;
	char	*tmp;

	det = ft_split(t, ' ');
	ft_check_paramnum(det, 2);
	tmp = ft_strdup(det[1]);
	ft_free_buf(det);
	det = ft_split(tmp, ',');
	ft_check_paramnum(det, 3);
	free(tmp);
	if (det[0] != 0 && det[1] != 0 && det[2] != 0)
	{
		r = ft_atoi(det[0]);
		g = ft_atoi(det[1]);
		b = ft_atoi(det[2]);
	}
	else
		return (0);
	ft_free_buf(det);
	return (convertrgbtoint(r, g, b));
}
