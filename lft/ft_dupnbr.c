/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:33:35 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/31 00:33:44 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dupnbr(char **nums)
{
	int	i;
	int	s;
	int	l;

	l = 0;
	while (nums[l])
		l++;
	i = 0;
	while (l > i + 1)
	{
		s = i + 1;
		while(s < l && (ft_atoi(nums[i]) != ft_atoi(nums[s])))
			s++;
		if (s != l)
			return (1);
		i++;
	}
	return (0);
}
