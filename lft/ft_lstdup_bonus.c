/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:42:52 by clems             #+#    #+#             */
/*   Updated: 2021/12/02 10:58:40 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// create a new list, cloning the content of the given one
void	ft_lstdup_bonus(t_list *src, t_list *dest)
{
	if (src)
	{
		dest = ft_lstnew(src->content);
		src = src->next;
	}
	while (src)
	{
		ft_lstadd_back(&dest, ft_lstnew(src->content));
		src = src->next;
	}
}
