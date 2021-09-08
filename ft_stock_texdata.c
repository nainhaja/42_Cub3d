/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_texdata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:13:30 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/08 17:13:32 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_check_texname(char *t, char *tex)
{
	char *tmp;

	tmp = ft_strdup("");
	if (ft_strcmp(tex, tmp))
	{
		ft_putstr("Error Double tex \n");
		free(tmp);
		exit(0);
	}
	free(tmp);
	free(tex);
	tex = ft_check_xpm(ft_stock_textures(t));
	if (tex == 0)
	{
		ft_putstr("Error Wrong texture path");
		free(tex);
		exit(0);
	}
	return (tex);
}

void	ft_getcolour(char *t, int *colour)
{
	*colour = ft_check_sol(t);
	if (*colour == 0)
	{
		ft_putstr("Error Wrong colors");
		exit(0);
	}
}

void	stock_resolutions(char **str, char *t)
{
	if (ft_stockdetails(str, t) == 1)
	{
		ft_putstr("Error Wrong resolutions arguments");
		exit(0);
	}
	if (g_width >= 2550)
		g_width = 2550;
	if (g_length >= 1400)
		g_length = 1400;
	if (g_width <= 100 || g_length <= 100)
	{
		ft_putstr("Error Small resolutions");
		exit(0);
	}
}

void	stock_texture_data(char **stock, char **str, char *t)
{
	if (t[0] != '\0')
	{
		if (ft_strcmp(str[0], "R") == 0)
			stock_resolutions(str, t);
		else if (ft_strcmp(str[0], "NO") == 0)
			g_northtex = ft_check_texname(t, g_northtex);
		else if (ft_strcmp(str[0], "SO") == 0)
			g_southtex = ft_check_texname(t, g_southtex);
		else if (ft_strcmp(str[0], "EA") == 0)
			g_easttex = ft_check_texname(t, g_easttex);
		else if (ft_strcmp(str[0], "WE") == 0)
			g_westtex = ft_check_texname(t, g_westtex);
		else if (ft_strcmp(str[0], "S") == 0)
			g_spritetex = ft_check_texname(t, g_spritetex);
		else if (ft_strcmp(str[0], "F") == 0)
			ft_getcolour(t, &g_f_colour);
		else if (ft_strcmp(str[0], "C") == 0)
			ft_getcolour(t, &g_c_colour);
		else if (ft_stock(*stock, t, 0) == 1)
			ft_error();
	}
	else if (g_empty_line == 1 && t[0] == '\0')
		ft_error();
}
