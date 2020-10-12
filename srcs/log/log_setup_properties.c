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

void	log_resolution(t_scene *scene)
{
	ft_printf("\n");
}

void	log_alight(void *sp)
{
	ft_printf("color: %d | pos: %d, %d, %d | diameter: %d\n",
	((t_sp *)sp)->color,
	((t_sp *)sp)->pos.x, ((t_sp *)sp)->pos.y, ((t_sp *)sp)->pos.z,
	((t_sp *)sp)->diameter);
}

void	log_camera(void *sq)
{
	ft_printf("color: %d | pos: %d, %d, %d | side: %d\n",
	((t_sq *)sq)->color,
	((t_sq *)sq)->pos.x, ((t_sp *)sq)->pos.y, ((t_sp *)sq)->pos.z,
	((t_sq *)sq)->side);
}

void	log_light(void *cy)
{
	ft_printf("color: %d | pos: %d, %d, %d | dimater: %d | height: %d\n",
	((t_cy *)cy)->color,
	((t_cy *)cy)->pos.x, ((t_sp *)cy)->pos.y, ((t_sp *)cy)->pos.z,
	((t_cy *)cy)->diameter,
	((t_cy *)cy)->height);
}
