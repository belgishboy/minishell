/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:56:01 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 17:01:00 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// apply the function f to every element of the current
// and every following element
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != 0 && f != 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
