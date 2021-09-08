/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:00:46 by nainhaja          #+#    #+#             */
/*   Updated: 2020/12/01 00:00:51 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define RAD(x) (x * M_PI / 180)
# define DEG(x) (x * 180 / M_PI)

typedef struct		s_imgptr{
	int				x;
	int				y;
	float			xhalf;
	float			yhalf;
	float			xoff;
	double			ray_distance;
	float			rotation;
}					t_imgptr;

typedef struct		s_hv{
	float			x;
	float			y;
	float			xstep;
	float			ystep;
	float			distance;
	int				s_found;
}					t_hv;

typedef struct		s_player{
	float			x;
	float			y;
	float			rotationangle;
	int				walkdirection;
	int				turndirection;
	double			dis;
	int				found;
}					t_player;

typedef struct		s_imggptr{
	int				*tex_data;
	void			*i_p;
	int				s_l;
	int				end;
	int				bpp;
	int				x;
	int				y;
	int				bits;
}					t_imggptr;

typedef struct		s_bitmapheader{
	uint16_t		bitcount;
	int				width_in_bytes;
	uint32_t		imagesize;
	uint32_t		bisize;
	uint32_t		bfoffbits;
	uint32_t		filesize;
	uint16_t		biplanes;
}					t_bitmapheader;
t_imggptr			g_no;
t_imggptr			g_so;
t_imggptr			g_we;
t_imggptr			g_ea;
t_imggptr			g_spritee;
t_imggptr			g_img;
t_imgptr			*g_sprite;
t_imgptr			g_temp;
t_player			g_p;
t_player			g_wall;
t_hv				g_horizontal;
t_hv				g_vertical;
float				g_rotation;
int					g_f_colour;
int					g_c_colour;
int					g_indicator;
void				*g_mlx_ptr;
void				*g_win_ptr;
void				*g_i_p;
int					*g_img_data;
int					g_width;
int					g_length;
int					g_width_max;
int					g_length_max;
float				g_theta;
int					g_h;
int					g_k;
int					g_a;
int					g_empty_line;
int					g_ray_count;
char				**g_b;
char				**g_m;
int					g_sc;
char				*g_northtex;
char				*g_southtex;
char				*g_easttex;
char				*g_westtex;
char				*g_spritetex;
int					ft_check_map();
void				dda(int x0, int y0, int x1, int y1);
void				ft_pixel_put(int *g_img_data, int xt, int yt, int color);
int					ft_checkspritesh();
int					ft_checkh();
int					ft_checkv();
void				ft_draw_sprite_column(int sprc);
int					ft_checkspriteh();
int					ft_checkspritesh();
int					ft_checkspriteh();
int					ft_checkspritev();
int					ft_checkconditions(int h, int k);
void				ft_draw();
void				ft_draw_column(int hvhit);
int					ft_grr();
void				sorting_sprites();
void				ft_raycast();
void				ft_player_mouvement(float *s);
int					key_press(int key);
int					key_release(int key);
int					ft_stock(char *stock, char *t, int c);
char				*ft_check_xpm(char *s);
char				*ft_stock_textures(char *t);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);
int					ft_stockdetails(char **det, char *t);
int					ft_check_sol(char *t);
char				*ft_itoa(int a);
void				ft_putnbr(int a);
void				save_bitmap(void);
int					convertrgbtoint(int r, int g, int b);
int					converthextob(int rgb);
int					converthextog(int rgb);
int					converthextor(int rgb);
int					ft_countsprites(void);
int					ft_checkconditionss(void);
void				stock_texture_data(char **stock, char **stockk, char *t);
void				ft_init(char *str);
void				ft_save_screenshot(void);
void				mlx_stock(void);
int					update(void);
int					ft_isdigit(int str);
void				*ft_memcpy(void *str, const void *str2, size_t n);
void				ft_check_paramnum(char **det, int num);
int					ft_check_direction(char direction);
void				ft_free_buf(char **det);
void				ft_free(void);
void				ft_check_player(char *stock, char *t, int c);
char				ft_get_length(int ab);
void				ft_error(void);
void				ft_free_buffers(char **stockk, char *t);
void				ft_check_file(int fd, char *str);
void				ft_errorr(void);
void				ft_wrong_arguments(void);
void				ft_putchar (char c);
void				ft_putstr(char *str);
int					ft_strcmp(const char *str, const char *to_find);
void				ft_fill_blank(void);
void				ft_get_sizemax();
void				ft_remplir_map(void);
void				ft_check_nulltex(void);
void				ft_collision(void);
int					ft_exit(void);
#endif
