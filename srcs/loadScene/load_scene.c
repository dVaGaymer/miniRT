/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvagaymer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:07:20 by dvagaymer         #+#    #+#             */
/*   Updated: 2020/08/23 18:10:56 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ft_printf.h>
#include <get_next_line.h>
#include "../../includes/minirt.h"

int	load_scene(const char *fileName, t_scene *scene)
{
	int	fd;
	char	*line;

	fd = open(fileName, O_RDONLY);
	ft_bzero(scene, sizeof(t_scene));
	while (get_next_line(fd, &line))
	{
		parse_line(line, scene);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (0);
}

/**
 * Returns	-1 when not valid
 * 		0 if useless line
 * 		1 if valid line
**/
void	parse_line(char *line, t_scene *scene)
{
	while (ft_isspace(*line))
		line++;
	if (*line == '#' || *line == 0)
		return ;
	else if (*line == 'R' && *(line + 1) == 32)
		read_resolution(line + 1, scene);
	else if (*line == 'A' && *(line + 1) == 32)
		read_alight(line + 1, scene);
	else if (*line == 'c' && *(line + 1) == 32)
		read_camera(line + 1, scene);
	else if (*line == 'l' && *(line + 1) == 32)
		read_light(line + 1, scene);
	else if (*line == 'p' && *(line + 1) == 'l')
		read_plane(line + 2, scene);
	else if (*line == 's' && *(line + 1)	== 'p')
		read_sphere(line + 2, scene);
	else if (*line == 's' && *(line + 1) == 'q')
		read_square(line + 2, scene);
	else if (*line == 'c' && *(line + 1) == 'y')
		read_cylinder(line + 2, scene);
	else if (*line == 't' && *(line + 1) == 'r')
		read_triangle(line + 2, scene);
}
