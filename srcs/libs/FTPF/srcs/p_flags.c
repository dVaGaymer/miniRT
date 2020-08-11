/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:22:53 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:32:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Function: apply_p_flags
** ------------------------
**
** const char *pos: input string
** t_info *si:      info structure
** t_flags *sf:     flag structure
** int  n:          num to print
*/

void	p_flags(t_info *si, t_flags *sf, char *str)
{
	int ls;
	int lt;
	int neg;
	int len;

	sf->width = *str == 48 && !sf->prc ? sf->width - 1 : sf->width - 2;
	len = *str == '-' ? ft_strlen(str + 1) : ft_strlen(str);
	neg = *str == '-' ? 1 : 0;
	lt = sf->prc > (int)ft_strlen(str) - neg ? sf->prc + neg : ft_strlen(str);
	ls = lt == 0 || lt == -1 ? ft_strlen(str) : lt;
	lt = sf->width > lt ? sf->width : lt;
	ls = (sf->zero && sf->prc == -1) ? lt : ls;
	if (!sf->neg)
		space(lt - ls, 0, si);
	write(1, "-", *str == '-' ? 1 : 0);
	write(1, "0x", 2);
	space(ls - ft_strlen(str), 1, si);
	if (!(!sf->prc && *str == 48))
		ft_putstr_fd(*str == '-' ? str + 1 : str, 1);
	if (sf->neg)
		space(lt - ls, 0, si);
	si->t += ft_strlen(str) + 2;
	si->t = *str == 48 && !sf->prc ? si->t - 1 : si->t;
	if (str)
		free(str);
}

void	apply_perc(t_info *si, t_flags *sf)
{
	if (!sf->neg)
		space(sf->width - 1, sf->zero, si);
	write(1, "%%", 1);
	if (sf->neg)
		space(sf->width - 1, 0, si);
	si->t++;
}
