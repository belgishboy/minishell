/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:54:54 by clems             #+#    #+#             */
/*   Updated: 2021/12/02 10:58:01 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// deletes the current and the following elements
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (lst && del && *lst)
	{
		while (*lst)
		{
			current = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = current;
		}
	}
	return ;
}
