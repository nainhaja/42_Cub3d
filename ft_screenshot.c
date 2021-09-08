/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 02:55:35 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/10 02:55:37 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_increment_vars(int *col, int *cool, int *cookl, int *row)
{
	*col = g_width;
	*cool = 0;
	*cookl = *cookl - 1;
	*row = *row + 1;
}

void	ft_initialise_vars(int *col, int *cool, int *cookl, int *row)
{
	*cookl = 800;
	*cool = 0;
	*col = g_width;
	*row = 0;
}

char	*ft_stock_buffer(uint32_t imagesize, int width_in_bytes)
{
	int				col;
	int				cool;
	int				cookl;
	int				row;
	unsigned char	*buf;

	ft_initialise_vars(&col, &cool, &cookl, &row);
	buf = malloc(imagesize);
	while (row <= g_length - 1)
	{
		while (col > 0)
		{
			buf[row * width_in_bytes + col * 3 + 0] =
				converthextob(g_img_data[cookl * g_width + cool]);
			buf[row * width_in_bytes + col * 3 + 1] =
				converthextog(g_img_data[cookl * g_width + cool]);
			buf[row * width_in_bytes + col * 3 + 2] =
				converthextor(g_img_data[cookl * g_width + cool]);
			cool++;
			col--;
		}
		ft_increment_vars(&col, &cool, &cookl, &row);
	}
	return ((char*)buf);
}

void	ft_write_in_file(unsigned char *h, uint32_t imagesize, int w_in_bytes)
{
	int	fd;

	fd = open("opooo.bmp", O_CREAT | O_WRONLY, 0777);
	write(fd, h, 54);
	write(fd, ft_stock_buffer(imagesize, w_in_bytes), imagesize);
	close(fd);
	exit(0);
}

void	save_bitmap(void)
{
	t_bitmapheader	h;
	unsigned char	*header;
	int				i;

	header = malloc(sizeof(char) * 54);
	i = 0;
	while (i++ < 54)
		header[i] = 0;
	h.bitcount = 24;
	h.width_in_bytes = ((g_width * h.bitcount + 31) / 32) * 4;
	h.imagesize = h.width_in_bytes * g_length;
	h.bfoffbits = 54;
	h.bisize = 40;
	h.filesize = 54 + h.imagesize;
	h.biplanes = 1;
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &h.filesize, 4);
	ft_memcpy(header + 10, &h.bfoffbits, 4);
	ft_memcpy(header + 14, &h.bisize, 4);
	ft_memcpy(header + 18, &g_width, 4);
	ft_memcpy(header + 22, &g_length, 4);
	ft_memcpy(header + 26, &h.biplanes, 2);
	ft_memcpy(header + 28, &h.bitcount, 2);
	ft_memcpy(header + 34, &h.imagesize, 4);
	ft_write_in_file(header, h.imagesize, h.width_in_bytes);
}
