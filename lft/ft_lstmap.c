/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:57:03 by clems             #+#    #+#             */
/*   Updated: 2021/12/02 11:04:47 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void			*f_;
	t_list			*res;
	t_list			*new;
	t_list			*org;

	res = NULL;
	new = NULL;
	org = lst;
	while (lst)
	{
		f_ = f(lst->content);
		if (f_)
		{
			new = ft_lstnew(f_);
			if (!new)
			{
				ft_lstclear(&lst, del);
				return (NULL);
			}
			ft_lstadd_back(&res, new);
		}
		lst = lst->next;
	}
	lst = org;
	return (res);
}
