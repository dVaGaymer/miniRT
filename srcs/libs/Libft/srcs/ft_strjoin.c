/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:07:42 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:37:56 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	int		aux;

	if (!s2)
		return (0);
	if (!s1)
		s1 = malloc(1);
	aux = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (*s1)
		*(str + aux++) = *s1++;
	while (*s2)
		*(str + aux++) = *s2++;
	*(str + len) = 0;
	return (str);
}
