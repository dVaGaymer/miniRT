/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 00:35:24 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/20 20:03:09 by dvagaymer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <ft_printf.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int	fd;
	char	*file_name = "scenes/default.rt";	

	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_printf("%s\n", line);
		free(line);
	}
	ft_printf("%s\n", line);
	if (line)
		free(line);
	ft_printf("Size of var is: %d\n", sizeof(fd) * 8);
	close(fd);
	return (0);
}
