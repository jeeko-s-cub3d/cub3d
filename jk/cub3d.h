/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:48:26 by hyko              #+#    #+#             */
/*   Updated: 2022/12/29 21:07:26 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "keycode_mac.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <float.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include "structs.h"

# define MINI_SCALE 0.25

# define WINDOW_WID 640
# define WINDOW_HEI 480

# define TEXTURE_SIZE 64

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_WINDOW_DESTROY 17

# define RAY_COUNT WINDOW_WID

# define BUFFER_SIZE 333

# define WALL_STRIP_WIDTH 1
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000001
# define RED 0xFF0000


int		key_press(int keycode, t_all *p_all);
void	init_player(t_all *p_all);
bool	hit_wall(double x, double y, t_all *p_all);
void	update_player(t_all *p_all);
void	fill_square(t_all *p_all, int x, int y, int color);
void	render_map(t_all *p_all);
void	draw_player(t_all *p_all);
int		ft_loop_hook(t_all *p_all);
int		key_release(int keycode, t_all *p_all);

void	ray_init(t_ray *p_ray, double ang);
void	calc_distance(t_all *p_all, t_temp_ray *hv);
double	distance_btw_points(double xa, double ya, double xb, double yb);
void	calc_ray(t_all *p_all, t_temp_ray *hv, int a, int b);
void	calc_horz_ray(t_all *p_all, t_temp_ray *p_horz);
void	calc_vert_ray(t_all *p_all, t_temp_ray *p_vert);
void	draw_line(t_all *p_all, double dx, double dy);
void	draw_one_ray(t_all *p_all, double ang, int i);
void	draw_ray(t_all *p_all);
double	normalize_fisheye(double ang);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(const char *s1, const char *s2);
char	*for_next(char *save);
char	*rtg(char *save);
char	*read_and_save(int fd, char *save);
char	*get_next_line(int fd);

void	locate_for_mini(int *xp, int *yp, t_point_db p);

void	render_3d_wall(t_all *p_all, int ray_num);
void	set_point_db(t_point_db *p_point, double x, double y);
void	render_3d(t_all *p_all);

void	draw_ceiling(t_all *p_all, int ray_num, int wall_top_pixel, int color);
void	draw_floor(t_all *p_all, int ray_num, int wall_bottom_pixel, int color);

void	init_mlx(t_all *p_all);
void	init_key(t_all *p_all);
void	ft_init(t_all *p_all);
void	loop_hook(t_all *p_all);
void	init_img_data(t_all *p_all);
void	init_map(t_all *p_all);
void	init_map_info(t_all *p_all);

void	parse_map(int argc, char **argv, t_all *p_all);
void	get_map_info(char *line, t_all *p_all);
void	is_vaild_map(t_all *p_all);
void	display_err_msg_and_exit(const char *err_msg);
void	is_valid_texture(char *path, int type, t_all *p_all);
void	is_valid_color(char *color, int type, t_all *p_all);
void	is_valid_tile(char *line, t_all *p_all);
void	free_double_pointer(char **arr);

void	set_texture_img(t_all *all);

bool	check_edge(t_all *p_all, t_point_db p1, t_point_db p2);

int		mouse(void);

void	set_point_i(t_point_i *p_point, int x, int y);

#endif
