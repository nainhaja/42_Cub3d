/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconditions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:36:39 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/01 19:38:34 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkconditions(int g_h, int g_k)
{
	if (g_b[g_k][g_h] == '1' || g_b[g_k][g_h] == '0' ||
		ft_check_direction(g_b[g_k][g_h]) == 1 || g_b[g_k][g_h] == '3')
		return (1);
	else if (g_b[g_k][g_h] == '2' || g_b[g_k][g_h] == ' ' ||
			g_b[g_k][g_h] != '\0')
		return (1);
	else
		return (0);
}

int	ft_checkconditionss(void)
{
	if (g_b[g_k][g_h] == '1' || g_b[g_k][g_h] == '0' ||
		ft_check_direction(g_b[g_k][g_h]) == 1 || g_b[g_k][g_h] == '3')
		return (1);
	else if (g_b[g_k][g_h] == '2' || g_b[g_k][g_h] == ' '
			|| g_b[g_k][g_h] != '\0')
		return (1);
	else
		return (0);
}
