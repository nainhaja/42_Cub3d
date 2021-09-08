/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortsprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:19:33 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/02 11:20:06 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sorting_sprites(void)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < g_sc)
	{
		while (j < g_sc - i)
		{
			if (g_sprite[j].ray_distance > g_sprite[j + 1].ray_distance)
			{
				g_temp = g_sprite[j];
				g_sprite[j] = g_sprite[j + 1];
				g_sprite[j + 1] = g_temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
