/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 00:35:24 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/23 18:12:19 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <ft_printf.h>
#include <fcntl.h>
#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_scene scene;

	if (argc == 1)
		return (0);
	if (load_scene(*(argv + 1), &scene) == -1)
		return (0);
	printf("cy diameter: %f", ((t_cy *)scene.cys->content)->pos.z);
	return (0);
}
