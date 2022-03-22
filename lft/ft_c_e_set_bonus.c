/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_e_set_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:31:01 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 11:54:29 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check if the given char is part of the set
int	ft_c_e_set_bonus(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen((char *)set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
