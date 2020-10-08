/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_polygons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvagaymer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:21:56 by dvagaymer         #+#    #+#             */
/*   Updated: 2020/08/23 18:11:51 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	read_plane(char *line, t_scene *sc)
{
	t_pl	*content;
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	content = (t_pl *)malloc(sizeof(t_pl));
	content->pos = read_vector(&line);	
	content->norm = read_vector(&line);
	content->color = read_color(&line);
	lst->content = content;
	ft_lstadd_back(&(sc->pls), lst);
}

void	read_sphere(char *line, t_scene *sc)
{
	t_sp	*content;
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	content = (t_sp *)malloc(sizeof(t_sp));
	content->pos = read_vector(&line);	
	content->diameter = ft_atof(line);
	while (ft_isspace(*line++));
	line = ft_strchr(line, ' ') + 1;
	content->color = read_color(&line);
	lst->content = content;
	ft_lstadd_back(&(sc->sps), lst);
}

void	read_square(char *line, t_scene *sc)
{
	t_sq	*content;
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	content = (t_sq *)malloc(sizeof(t_sq));
	content->pos = read_vector(&line);	
	content->norm = read_vector(&line);
	content->side = ft_atof(line);
	while (ft_isspace(*line++));
	line = ft_strchr(line, ' ');
	content->color = read_color(&line);
	lst->content = content;
	ft_lstadd_back(&(sc->sqs), lst);
}

void	read_cylinder(char *line, t_scene *sc)
{
	t_cy	*content;
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	content = (t_cy *)malloc(sizeof(t_cy));
	content->pos = read_vector(&line);	
	content->norm = read_vector(&line);
	content->diameter = ft_atof(line);
	while (ft_isspace(*line++));
	line = ft_strchr(line, ' ');
	content->height = ft_atof(line);
	while (ft_isspace(*line++));
	line = ft_strchr(line, ' ');
	content->color = read_color(&line);
	lst->content = content;
	ft_lstadd_back(&(sc->cys), lst);
}

void	read_triangle(char *line, t_scene *sc)
{
	t_tr	*content;
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	content = (t_tr *)malloc(sizeof(t_tr));
	content->p0 = read_vector(&line);	
	content->p1 = read_vector(&line);	
	content->p2 = read_vector(&line);	
	lst->content = content;
	ft_lstadd_back(&(sc->trs), lst);
}
