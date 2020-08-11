/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 19:27:39 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:32:47 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	space(int num, int zero, t_info *si)
{
	int		aux;
	char	c;

	if (num <= 0)
		return ;
	aux = -1;
	c = 32;
	if (zero)
		c = 48;
	while (++aux < num)
		si->t += write(1, &c, 1);
}
