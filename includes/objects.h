/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvagaymer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:16:38 by dvagaymer         #+#    #+#             */
/*   Updated: 2020/08/20 21:55:29 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}		t_vec3;
typedef	struct	s_pos
{
	float	x;
	float	y;
	float	z;
}		t_pos;
typedef	struct	s_a
{
	float	brightness;
	int	color;
}		t_a;
typedef	struct	s_cam
{
	t_pos	pos;
	t_vec3	norm;
	int	fov;
	t_cam	next
}		t_cam;
typedef	struct	s_light
{
	t_pos	pos;
	float	brightness;
	int	color;	
	t_light	next;
}		t_light;
typedef	struct	s_pl
{
	t_pos	pos;
	t_vec3	norm;
	int	color;
	t_pl	next;
}		t_pl;
typedef	struct	s_sp
{
	t_pos	pos;
	float	diameter;
	int	color;
	t_sp	next;
}		t_sp;
typedef	struct	s_sq
{
	t_pos	pos;
	t_vec3	norm;
	float	side;
	int	color;
	t_sq	next;
}		t_sq;
typedef	struct	s_cy
{
	t_pos	pos;
	t_vec3	norm;
	float	diameter;
	float	height;
	int	color;
	t_cy	next;
}		t_cy;
typedef	struct	s_tr
{
	t_pos	p0;
	t_pos	p1;
	t_pos	p2;
	int	color;
	t_tr	next;
}		t_tr;
typedef	struct	s_scene
{
	int	w;
	int	h;
	t_a	ambient;
	t_cam	cameras;
	t_light	lights;
	t_pl	pls;
	t_sp	sps;
	t_sq	sqs;
	t_cy	cys;
	t_tr	trs;
}		t_scene;
