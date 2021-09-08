/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:46:55 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/01 19:49:43 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_stockdetails(char **det, char *t)
{
	int mj;
	int cpt;

	mj = 0;
	cpt = 0;
	while (det[mj] != NULL)
	{
		g_m[cpt] = det[mj];
		cpt++;
		mj++;
	}
	if (cpt != 3)
		return (1);
	else
	{
		t = 0;
		g_width = ft_atoi(g_m[1]);
		g_length = ft_atoi(g_m[2]);
	}
	return (0);
}

char	*ft_stock_textures(char *t)
{
	char	**det;
	int		i;

	i = 0;
	det = ft_split(t, ' ');
	while (det[i])
		i++;
	if (i != 2)
	{
		ft_putstr("Error Wrong texture arguments\n");
		exit(0);
	}
	t = ft_strdup(det[1]);
	i = 0;
	while (det[i])
	{
		free(det[i]);
		i++;
	}
	free(det);
	return (t);
}

char	*ft_check_xpm(char *s)
{
	char	*d;
	int		filedesc;
	char	*tmp;

	filedesc = open(s, O_WRONLY | O_APPEND);
	if (s[0] == '.' && s[1] == '/')
	{
		tmp = ft_strdup(s);
		free(s);
		s = ft_substr(tmp, 2, ft_strlen(tmp) - 1);
		free(tmp);
	}
	d = ft_strchr(s, '.');
	if (filedesc < 0)
		return (0);
	else
	{
		if (ft_strcmp(d, ".xpm") == 0)
			return (s);
		else
			return (0);
	}
	close(filedesc);
}
