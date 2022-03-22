/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:33 by clems             #+#    #+#             */
/*   Updated: 2021/12/02 11:04:24 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// append an element at the end of the given list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*finit;

	if (lst)
	{
		if (*lst)
		{
			finit = ft_lstlast(*lst);
			finit->next = new;
		}
		else
			*lst = new;
	}
}
