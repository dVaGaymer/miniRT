/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvagaymer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:03:37 by dvagaymer         #+#    #+#             */
/*   Updated: 2020/08/23 18:12:43 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../../includes/minirt.h"

t_vec3	read_vector(char **line)
{
	t_vec3	vec;

	vec.x = ft_atof(*line);
	*line = ft_strchr(*line, ',') + 1;
	vec.y = ft_atof(*line);
	*line = ft_strchr(*line, ',') + 1;
	vec.z = ft_atof(*line);
	*line = ft_strchr(*line, ' ') + 1;
	return (vec);
}

int	read_color(char **line)
{
	int	color;

	*line = ft_strchr(*line, ' ') + 1;
	color = ft_atoi(*line) << 24;
	*line = ft_strchr(*line, ',') + 1;
	color = color | ft_atoi(*line) << 16;
	*line = ft_strchr(*line, ',') + 1;
	color = color | ft_atoi(*line) << 8;
	color = color | 255;
	return (color);
}
