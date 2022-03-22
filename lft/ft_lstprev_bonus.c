/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprev_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:36:13 by clems             #+#    #+#             */
/*   Updated: 2021/05/28 18:12:53 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// gets a pointer to an element and returns the pointer to the previous element
t_list	*ft_lstprev_bonus(t_list **lst, t_list *follow)
{
	t_list	*current;

	current = NULL;
	if (lst)
	{
		current = *lst;
		while (current->next != 0 && current->next != follow)
			current = current->next;
	}
	return (current);
}
