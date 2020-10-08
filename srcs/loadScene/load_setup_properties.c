/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_setup_properties.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvagaymer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:24:57 by dvagaymer         #+#    #+#             */
/*   Updated: 2020/08/23 18:11:34 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <libft.h>

void	read_resolution(char *line, t_scene *sc)
{
	sc->w = ft_atoi(line);
	while (ft_isspace(*line++));
	line = ft_strchr(line, ' ') + 1;
	sc->h = ft_atoi(line);
}

void	read_alight(char *line, t_scene *sc)
{
	(sc->ambient).brightness = ft_atof(line);
	while (ft_isspace(*line++));
	line = ft_strchr(line, ' ') + 1;
	(sc->ambient).color = read_color(&line);
}

void	read_camera(char *line, t_scene *sc)
{
	t_cam	*content;
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	content = (t_cam *)malloc(sizeof(t_cam));
	content->pos = read_vector(&line);	
	content->norm = read_vector(&line);
	content->fov = ft_atoi(line);
	lst->content = content;
	ft_lstadd_back(&(sc->cameras), lst);
}

void	read_light(char *line, t_scene *sc)
{
	t_light	*content;
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	content = (t_light *)malloc(sizeof(t_light));
	content->pos = read_vector(&line);	
	content->brightness = ft_atof(line);
	while (ft_isspace(*line++));
	line = ft_strchr(line, ' ') + 1;
	content->color = read_color(&line);	
	lst->content = content;
	ft_lstadd_back(&(sc->lights), lst);
}
