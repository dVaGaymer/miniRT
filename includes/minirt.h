/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvagaymer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:16:38 by dvagaymer         #+#    #+#             */
/*   Updated: 2020/08/23 17:48:52 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include <libft.h>
#include "rtmath.h"

typedef	struct	s_win_info
{
	void 	*mlx_ptr;
	void	*mlx_win;
}				t_win_info;
typedef	struct	s_canvas_info
{
	void	*canvas;
	char	*addr;
	int		width;
	int		height;
	int 	bpp;
	int		size_line;
	int		endian;
}				t_canvas_info;

typedef	enum	e_type
{
	PLANE,
	SPHERE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}				t_type;
typedef	struct	s_a
{
	float	brightness;
	int	color;
}		t_a;
typedef	struct	s_cam
{
	t_vec3	pos;
	t_vec3	norm;
	int	fov;
}		t_cam;
typedef	struct	s_light
{
	t_vec3	pos;
	float	brightness;
	int	color;	
}		t_light;
typedef	struct	s_pl
{
	t_vec3	pos;
	t_vec3	norm;
	int	color;
}		t_pl;
typedef	struct	s_sp
{
	t_vec3	pos;
	float	diameter;
	int	color;
}		t_sp;
typedef	struct	s_sq
{
	t_vec3	pos;
	t_vec3	norm;
	float	side;
	int	color;
}		t_sq;
typedef	struct	s_cy
{
	t_vec3	pos;
	t_vec3	norm;
	float	diameter;
	float	height;
	int	color;
}		t_cy;
typedef	struct	s_tr
{
	t_vec3	p0;
	t_vec3	p1;
	t_vec3	p2;
	int	color;
}		t_tr;
typedef	struct	s_fragment
{
	t_type	type;
	t_vec3	color;
	t_vec3	pos;
	t_vec3	normal;
	t_vec3	material;
}				t_fragment;
typedef	struct	s_scene
{
	int	w;
	int	h;
	t_a	ambient;
	t_list	*cameras;
	t_list	*lights;
	t_list	*pls;
	t_list	*sps;
	t_list	*sqs;
	t_list	*cys;
	t_list	*trs;
}		t_scene;
void	minirt(void);
int		load_scene(const char *fileName, t_scene *scene);
void	parse_line(char *line, t_scene *scene);
void	read_resolution(char *line, t_scene *sc);
void	read_alight(char *line, t_scene *sc);
void	read_camera(char *line, t_scene *sc);
void	read_light(char *line, t_scene *sc);
void	read_plane(char *line, t_scene *sc);
void	read_sphere(char *line, t_scene *sc);
void	read_square(char *line, t_scene *sc);
void	read_cylinder(char *line, t_scene *sc);
void	read_triangle(char *line, t_scene *sc);
t_vec3	read_vector(char **line);
int		read_color(char **line);

//log
void	log_plane(void *pl);
void	log_sphere(void *sp);
void	log_square(void *sq);
void	log_cylinder(void *cy);
void	log_triangle(void *tr);

void	log_resolution(t_scene *scene);
void	log_alight(void *sp);
void	log_camera(void *sq);
void	log_light(void *cy);

int		shade(int x, int y, int width, int height, t_scene scene);
void	display(t_win_info *win_info, t_canvas_info *canvas_info, t_scene scene);
void	mlx_setup(t_win_info *win_info, t_canvas_info *canvas_info);
void	fill_pixel(t_canvas_info *canvas_info, int x, int y, int color);
void	close_window(int keycode, void *params);
#endif