/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:42:39 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:37:43 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	aux;

	aux = (long)n;
	if (aux < 0)
	{
		aux *= -1;
		ft_putchar_fd(45, fd);
	}
	if (aux > 9)
		ft_putnbr_fd(aux / 10, fd);
	ft_putchar_fd(aux % 10 + 48, fd);
}
