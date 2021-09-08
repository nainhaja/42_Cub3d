/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:43:26 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/10 01:43:28 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_sizemax(void)
{
	ft_remplir_map();
	ft_check_map();
}

void	ft_wrong_arguments(void)
{
	ft_putstr("Error Wrong arguments");
	exit(0);
}

void	ft_error(void)
{
	ft_putstr("ERROR empty line in map");
	exit(0);
}

void	ft_errorr(void)
{
	ft_putstr("ERROR missing informations");
	exit(0);
}

int		ft_countsprites(void)
{
	int	count;

	count = 0;
	g_h = 0;
	g_k = 0;
	while (g_k < g_length_max)
	{
		while (ft_checkconditionss())
		{
			if (g_b[g_k][g_h] == '2')
				count++;
			g_h++;
		}
		g_h = 0;
		g_k++;
	}
	g_k = 0;
	g_h = 0;
	return (count);
}
