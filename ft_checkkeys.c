/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_CheckKeys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:51:12 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/01 19:51:36 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key)
{
	if (key == 123)
		g_p.turndirection = 1;
	if (key == 124)
		g_p.turndirection = -1;
	if (key == 13)
		g_p.walkdirection = 1;
	if (key == 1)
		g_p.walkdirection = -1;
	if (key == 2)
	{
		g_p.walkdirection = 1;
		g_rotation = M_PI / 2;
	}
	if (key == 0)
	{
		g_p.walkdirection = -1;
		g_rotation = M_PI / 2;
	}
	if (key == 53)
		exit(0);
	return (0);
}

int		key_release(int key)
{
	if (key == 123)
		g_p.turndirection = 0;
	if (key == 124)
		g_p.turndirection = 0;
	if (key == 13)
		g_p.walkdirection = 0;
	if (key == 1)
		g_p.walkdirection = 0;
	if (key == 2)
	{
		g_p.walkdirection = 0;
		g_rotation = 0;
	}
	if (key == 0)
	{
		g_p.walkdirection = 0;
		g_rotation = 0;
	}
	return (0);
}

void	ft_check_player(char *stock, char *t, int c)
{
	if (c == 1 && g_empty_line == 1)
	{
		if (t[0] == '\0')
		{
			ft_putstr("Error empty line\n");
			free(stock);
			exit(0);
		}
		else if (g_p.found > 1)
		{
			ft_putstr("Error multiple players\n");
			exit(0);
		}
		else if (g_p.found == 0)
		{
			ft_putstr("Error player not found\n");
			exit(0);
		}
	}
	else if (t[0] == 0)
	{
		ft_putstr("Error missing map");
		exit(0);
	}
	g_empty_line = 1;
}

char	ft_get_length(int ab)
{
	if (g_width_max < ab + 1)
		g_width_max = ab + 1;
	g_length_max = g_a + 1;
	return ('\0');
}

void	ft_free_buffers(char **stockk, char *t)
{
	int i;

	i = 0;
	while (stockk[i])
	{
		free(stockk[i]);
		i++;
	}
	free(t);
	free(stockk);
}
