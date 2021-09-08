/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:16 by nainhaja          #+#    #+#             */
/*   Updated: 2020/11/30 23:59:20 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_arguments(int argc, char **argv, char **stock)
{
	if (argc >= 2)
	{
		if (argc == 3)
		{
			if (!(ft_strcmp(argv[2], "--save")))
				ft_save_screenshot();
			else
			{
				ft_putstr("Error Wrong arguments\n");
				exit(0);
			}
			free(*stock);
		}
		else if (argc > 3)
		{
			ft_putstr("Error Wrong arguments\n");
			exit(0);
		}
	}
}

int		main(int argc, char **argv)
{
	char	*t;
	char	*stock;
	char	**stockk;
	int		fd1;

	if (argc >= 2)
	{
		ft_init(argv[1]);
		fd1 = open(argv[1], O_RDONLY);
		ft_check_file(fd1, argv[1]);
		while (get_next_line(fd1, &t))
		{
			stockk = ft_split(t, ' ');
			stock_texture_data(&stock, stockk, t);
			ft_free_buffers(stockk, t);
		}
		mlx_stock();
		ft_stock(stock, t, 1);
		ft_get_sizemax();
		ft_check_arguments(argc, argv, &stock);
		mlx_loop_hook(g_mlx_ptr, update, (void*)0);
		mlx_loop(g_mlx_ptr);
	}
	else
		ft_wrong_arguments();
}
