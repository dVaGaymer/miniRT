/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:22:53 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:32:40 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Function: apply_x_flags
** ------------------------
**
** const char *pos: input string
** t_info *si:      info structure
** t_flags *sf:     flag structure
** int  n:          num to print
*/

void	x_flags(t_info *si, t_flags *sf, char *str)
{
	int ls;
	int lt;
	int neg;
	int len;

	len = *str == '-' ? ft_strlen(str + 1) : ft_strlen(str);
	neg = *str == '-' ? 1 : 0;
	lt = sf->prc > (int)ft_strlen(str) - neg ? sf->prc + neg : ft_strlen(str);
	ls = lt == 0 || lt == -1 ? ft_strlen(str) : lt;
	lt = sf->width > lt ? sf->width : lt;
	ls = sf->zero && sf->prc == -1 ? lt : ls;
	space(!sf->neg ? lt - ls : 0, 0, si);
	write(1, "-", *str == '-' ? 1 : 0);
	space(ls - ft_strlen(str), 1, si);
	*str = !sf->prc && *str == 48 ? ' ' : *str;
	*str = !sf->prc && *str == 32 && sf->width == 0 ? 0 : *str;
	ft_putstr_fd(*str == '-' ? str + 1 : str, 1);
	space(sf->neg ? lt - ls : 0, 0, si);
	si->t += ft_strlen(str);
	if (str)
		free(str);
}
