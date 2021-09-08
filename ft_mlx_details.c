/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_details.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:14:39 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/10 01:22:23 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_check_falsefile(void)
{
	if (g_no.i_p == 0 || g_so.i_p == 0 || g_ea.i_p == 0)
	{
		ft_putstr("Error Wrong texture path");
		exit(0);
	}
	else if (g_spritee.i_p == 0 || g_we.i_p == 0)
	{
		ft_putstr("Error Wrong texture path");
		exit(0);
	}
	else
	{
		g_no.tex_data = (int*)mlx_get_data_addr(g_no.i_p,
		&g_no.bits, &g_no.s_l, &g_no.end);
		g_so.tex_data = (int*)mlx_get_data_addr(g_so.i_p,
		&g_so.bits, &g_so.s_l, &g_so.end);
		g_we.tex_data = (int*)mlx_get_data_addr(g_we.i_p,
		&g_we.bits, &g_we.s_l, &g_we.end);
		g_ea.tex_data = (int*)mlx_get_data_addr(g_ea.i_p,
		&g_ea.bits, &g_ea.s_l, &g_ea.end);
		g_spritee.tex_data = (int*)mlx_get_data_addr(g_spritee.i_p,
		&g_spritee.bits, &g_spritee.s_l, &g_spritee.end);
	}
}

void	mlx_stock(void)
{
	ft_check_nulltex();
	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr, g_width, g_length, "Cub3D");
	g_i_p = mlx_new_image(g_mlx_ptr, g_width, g_length);
	g_img_data = (int*)mlx_get_data_addr(g_i_p,
	&g_img.bpp, &g_img.s_l, &g_img.end);
	g_no.i_p = mlx_xpm_file_to_image(g_mlx_ptr, g_northtex, &g_no.x, &g_no.y);
	g_so.i_p = mlx_xpm_file_to_image(g_mlx_ptr, g_southtex, &g_so.x, &g_so.y);
	g_we.i_p = mlx_xpm_file_to_image(g_mlx_ptr, g_westtex, &g_we.x, &g_we.y);
	g_ea.i_p = mlx_xpm_file_to_image(g_mlx_ptr, g_easttex, &g_ea.x, &g_ea.y);
	g_spritee.i_p = mlx_xpm_file_to_image(g_mlx_ptr,
	g_spritetex, &g_spritee.x, &g_spritee.y);
	mlx_check_falsefile();
	ft_free();
}

void	ft_save_screenshot(void)
{
	int sam;

	sam = 0;
	while (sam++ < 3)
		update();
	save_bitmap();
}

void	ft_init_tex(void)
{
	g_easttex = ft_strdup("");
	g_northtex = ft_strdup("");
	g_westtex = ft_strdup("");
	g_southtex = ft_strdup("");
	g_spritetex = ft_strdup("");
	g_f_colour = -1;
	g_c_colour = -1;
	g_length = -1;
	g_width = -1;
}

void	ft_init(char *str)
{
	int		size;
	int		fd;
	char	*t;

	size = 0;
	fd = open(str, O_RDONLY);
	ft_check_file(fd, str);
	g_width_max = 0;
	while (get_next_line(fd, &t))
	{
		free(t);
		size++;
	}
	free(t);
	g_b = malloc(sizeof(char**) * (size + 1));
	g_m = malloc(sizeof(char**) * (size + 1));
	g_p.found = 0;
	close(fd);
	ft_init_tex();
	g_empty_line = 0;
}
