/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 00:35:24 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/23 18:16:10 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <ft_printf.h>
#include <fcntl.h>
#include "../includes/minirt.h"

static void free_scene(t_scene *scene);
void		log_scene_info(t_scene scene);

int	main(int argc, char **argv)
{
	t_scene scene;

	if (argc == 1)
		return (0);
	if (load_scene(*(argv + 1), &scene) == -1)
		ft_printf("Loaded!");
	log_scene_info(scene);
	free_scene(&scene);
	ft_printf("Memory freed!\n");
	return (0);
}

void		log_scene_info(t_scene scene)
{
	//ft_printf("\nCameras:\n");
	//ft_lstiter(scene.cameras, &log_camera);
	//ft_printf("\nLights:\n");
	//ft_lstiter(scene.lights, &log_light);
	ft_printf("\nPlanes:\n");
	ft_lstiter(scene.pls, &log_plane);
	ft_printf("\nSpheres:\n");
	ft_lstiter(scene.sps, &log_sphere);
	ft_printf("\nSquares:\n");
	ft_lstiter(scene.sqs, &log_square);
	ft_printf("\nCylinder:\n");
	ft_lstiter(scene.cys, &log_cylinder);
	ft_printf("\nTriangles:\n");
	ft_lstiter(scene.trs, &log_triangle);
}

static void free_scene(t_scene *scene)
{
	ft_lstclear(&scene->cameras, free);
	ft_lstclear(&scene->lights, free);
	ft_lstclear(&scene->pls, free);
	ft_lstclear(&scene->sps, free);
	ft_lstclear(&scene->sqs, free);
	ft_lstclear(&scene->cys, free);
	ft_lstclear(&scene->trs, free);
}
