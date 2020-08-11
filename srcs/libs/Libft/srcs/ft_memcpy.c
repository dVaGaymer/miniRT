/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:16:01 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:37:32 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	aux;

	if (n == 0 || src == dst)
		return (dst);
	aux = 0;
	while (aux < n)
	{
		*(unsigned char *)(dst + aux) = *(unsigned char *)(src + aux);
		aux++;
	}
	return ((void *)dst);
}
