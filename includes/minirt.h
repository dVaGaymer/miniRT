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

#include <libft.h>

typedef	struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}		t_vec3;
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
int	minirt(void);
int	load_scene(const char *fileName, t_scene *scene);
int	parse_line(char *line, t_scene *scene);
int	read_resolution(char *line, t_scene *sc);
int	read_alight(char *line, t_scene *sc);
int	read_camera(char *line, t_scene *sc);
int	read_light(char *line, t_scene *sc);
int	read_plane(char *line, t_scene *sc);
int	read_sphere(char *line, t_scene *sc);
int	read_square(char *line, t_scene *sc);
int	read_cylinder(char *line, t_scene *sc);
int	read_triangle(char *line, t_scene *sc);
t_vec3	read_vector(char **line);
int	read_color(char **line);
