/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:21:11 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:43:38 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		get_next_line(int fd, char **line);
int		eof(char **prev, char **aux, char **line);
int		endofline(char *line, int nread);
int		copyline(char *aux, char **line);
int		linelen(char *aux);

#endif
