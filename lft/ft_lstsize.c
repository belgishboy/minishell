/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:09:00 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 19:24:37 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count and return the length of a list
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 1;
	current = lst;
	if (lst)
	{
		while ((current->next) != NULL)
		{
			current = current->next;
			i++;
		}
	}
	else
		return (0);
	return (i);
}
