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
	int	status;

	status = 0;
	fd = open(fileName, O_RDONLY);
	ft_bzero(scene, sizeof(t_scene));
	while (get_next_line(fd, &line) && !status)
	{
		status = parse_line(line, scene);
		free(line);
	}
	close(fd);
	return (status);
}

/**
 * Returns	-1 when not valid
 * 		0 if useless line
 * 		1 if valid line
**/
int	parse_line(char *line, t_scene *scene)
{
	while (ft_isspace(*line))
		line++;
	if (*line == '#' || *line == 0)
		return (0);
	else if (*line == 'R' && *(line + 1) == 32)
		return (read_resolution(line + 1, scene));
	else if (*line == 'A' && *(line + 1) == 32)
		return (read_alight(line + 1, scene));
	else if (*line == 'c' && *(line + 1) == 32)
		return (read_camera(line + 1, scene));
	else if (*line == 'l' && *(line + 1) == 32)
		return (read_light(line + 1, scene));
	else if (*line == 'p' && *(line + 1) == 'l')
		return (read_plane(line + 2, scene));
	else if (*line == 's' && *(line + 1)	== 'p')
		return (read_sphere(line + 2, scene));
	else if (*line == 's' && *(line + 1) == 'q')
		return (read_square(line + 2, scene));
	else if (*line == 'c' && *(line + 1) == 'y')
		return (read_cylinder(line + 2, scene));
	else if (*line == 't' && *(line + 1) == 'r')
		return (read_triangle(line + 2, scene));
	return (-1);
}
