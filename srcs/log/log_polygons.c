/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_polygons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvagaymer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:21:56 by dvagaymer         #+#    #+#             */
/*   Updated: 2020/10/08 18:11:51 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <ft_printf.h>

void	log_plane(void *pl)
{
	ft_printf("color: %d | pos: %d, %d, %d\n",
	((t_pl *)pl)->color,
	((t_pl *)pl)->pos.x, ((t_pl *)pl)->pos.y, ((t_pl *)pl)->pos.z);
}

void	log_sphere(void *sp)
{
	ft_printf("color: %d | pos: %d, %d, %d | diameter: %d\n",
	((t_sp *)sp)->color,
	((t_sp *)sp)->pos.x, ((t_sp *)sp)->pos.y, ((t_sp *)sp)->pos.z,
	((t_sp *)sp)->diameter);
}

void	log_square(void *sq)
{
	ft_printf("color: %d | pos: %d, %d, %d | side: %d\n",
	((t_sq *)sq)->color,
	((t_sq *)sq)->pos.x, ((t_sp *)sq)->pos.y, ((t_sp *)sq)->pos.z,
	((t_sq *)sq)->side);
}

void	log_cylinder(void *cy)
{
	ft_printf("color: %d | pos: %d, %d, %d | dimater: %d | height: %d\n",
	((t_cy *)cy)->color,
	((t_cy *)cy)->pos.x, ((t_sp *)cy)->pos.y, ((t_sp *)cy)->pos.z,
	((t_cy *)cy)->diameter,
	((t_cy *)cy)->height);
}

void	log_triangle(void *tr)
{
	ft_printf("color: %d | p0: %d, %d, %d | p1: %d, %d, %d | p2: %d, %d, %d\n",
	((t_tr *)tr)->color,
	((t_tr *)tr)->p0.x, ((t_tr *)tr)->p0.y, ((t_tr *)tr)->p0.z,
	((t_tr *)tr)->p1.x, ((t_tr *)tr)->p1.y, ((t_tr *)tr)->p1.z,
	((t_tr *)tr)->p2.x, ((t_tr *)tr)->p2.y, ((t_tr *)tr)->p2.z);
}
