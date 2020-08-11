/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:30:09 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:33:32 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

int	get_next_line(int fd, char **line)
{
	static char	*prev[4096];
	char		*aux;
	int			cnt;
	char		*temp;

	aux = NULL;
	if ((read(fd, aux, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0 || !line) ||
			!(aux = malloc(BUFFER_SIZE + 1)))
		return (-1);
	prev[fd] = !(prev[fd]) ? ft_strdup("") : prev[fd];
	while (!(ft_strchr(prev[fd], 10)))
	{
		if (!(cnt = read(fd, aux, BUFFER_SIZE)))
			return (eof(&prev[fd], &aux, line));
		*(aux + cnt) = 0;
		temp = prev[fd];
		prev[fd] = ft_strjoin(prev[fd], aux);
		free(temp);
	}
	copyline(prev[fd], line);
	temp = prev[fd];
	prev[fd] = ft_strdup(ft_strchr(prev[fd], 10) + 1);
	free(temp);
	free(aux);
	return (1);
}

int	eof(char **prev, char **aux, char **line)
{
	if (*prev)
	{
		*line = ft_strdup(*prev);
		free(*prev);
		*prev = NULL;
		free(*aux);
	}
	return (0);
}

int	copyline(char *aux, char **line)
{
	int	i;
	int	len;

	i = 0;
	if (!aux || *aux == 10)
	{
		*line = ft_strdup("");
		return (1);
	}
	len = linelen(aux);
	if (!(*line = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	*(*line + len) = 0;
	while (*(aux + i) != 10 && *(aux + i))
	{
		*(*line + i) = *(aux + i);
		i++;
	}
	return (1);
}

int	linelen(char *aux)
{
	int	cnt;

	cnt = 0;
	if (*(aux + cnt) == 10)
		return (1);
	while (*(aux + cnt) != 10 && *(aux + cnt))
		cnt++;
	return (cnt);
}
