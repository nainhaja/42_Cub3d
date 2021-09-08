/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:58:11 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/01 18:58:14 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_file(int fd, char *str)
{
	char *new;
	char *cub;

	cub = ft_strdup(".cub");
	new = ft_strchr(str, '.');
	if (new == 0 || (ft_strcmp(new, cub)) || fd == -1)
	{
		free(cub);
		ft_putstr("Error Wrong file name");
		exit(0);
	}
	free(cub);
}

int		ft_condition(int mj, int op)
{
	if (g_b[op][mj] == '0' || ft_check_direction(g_b[op][mj]) == 1 ||
		g_b[op][mj] == '2' || g_b[op][mj] == '3')
	{
		if (g_b[op][mj + 1] == ' ' || g_b[op][mj - 1] == ' ' ||
		g_b[op + 1][mj] == ' ' || g_b[op - 1][mj] == ' ')
		{
			ft_putstr("Error - > wrong map\n");
			exit(0);
		}
		else if (g_b[op][mj + 1] == 0 || g_b[op][mj - 1] == 0 ||
			g_b[op + 1][mj] == 0 || g_b[op - 1][mj] == 0)
		{
			ft_putstr("error wrong map\n");
			exit(0);
		}
	}
	return (1);
}

int		ft_check_map(void)
{
	int mj;
	int op;

	mj = 0;
	op = 0;
	while (op < g_length_max)
	{
		while (mj < g_width_max - 1)
		{
			if (!ft_condition(mj, op))
			{
				ft_putstr("Error Wrong map");
				exit(0);
			}
			mj++;
		}
		op++;
		mj = 0;
	}
	return (1);
}
