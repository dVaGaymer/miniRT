/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:28:17 by alopez-g          #+#    #+#             */
/*   Updated: 2020/08/09 23:37:09 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *l;
	t_list *aux;

	l = *lst;
	while (l != 0)
	{
		aux = l->next;
		(del)(l->content);
		free(l);
		l = aux;
	}
	*lst = 0;
}
