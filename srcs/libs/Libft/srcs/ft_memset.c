/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:00:37 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:37:36 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	aux;

	aux = 0;
	while (aux < len)
		*(unsigned char *)(b + aux++) = (unsigned char)c;
	return (b);
}
