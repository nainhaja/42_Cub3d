/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:58:18 by nainhaja          #+#    #+#             */
/*   Updated: 2019/07/09 15:19:09 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_remplir_map(void)
{
	g_h = 0;
	g_k = 0;
	while (g_k < g_length_max)
	{
		g_b[g_k] = malloc(sizeof(char) * (g_width_max + 1));
		while (g_m[g_k][g_h])
		{
			g_b[g_k][g_h] = g_m[g_k][g_h];
			g_h++;
		}
		while (g_h < g_width_max)
		{
			g_b[g_k][g_h] = ' ';
			g_h++;
		}
		g_b[g_k][g_h] = '\0';
		g_h = 0;
		g_k++;
	}
}

void	ft_check_nulltex(void)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strdup("");
	if (!ft_strcmp(g_spritetex, new))
		i = 1;
	else if (!ft_strcmp(g_easttex, new))
		i = 1;
	else if (!ft_strcmp(g_westtex, new))
		i = 1;
	else if (!ft_strcmp(g_northtex, new))
		i = 1;
	else if (!ft_strcmp(g_southtex, new))
		i = 1;
	else if (g_f_colour == -1 || g_c_colour == -1)
		i = 1;
	else if (g_width == -1 || g_c_colour == -1)
		i = 1;
	if (i == 1)
	{
		free(new);
		ft_errorr();
	}
	free(new);
}
