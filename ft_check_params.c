/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 03:48:11 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/13 03:48:14 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_paramnum(char **det, int num)
{
	int	i;

	i = 0;
	while (det[i])
		i++;
	if (i != num)
	{
		ft_putstr("Error Color arguments");
		exit(0);
	}
}

void	ft_free(void)
{
	free(g_northtex);
	free(g_westtex);
	free(g_easttex);
	free(g_spritetex);
	free(g_southtex);
}

void	ft_free_buf(char **det)
{
	int	i;

	i = 0;
	while (det[i])
	{
		free(det[i]);
		i++;
	}
	free(det);
}

int		ft_check_direction(char direction)
{
	if (direction == 'N' || direction == 'S' ||
	direction == 'E' || direction == 'W')
		return (1);
	else
		return (0);
}
