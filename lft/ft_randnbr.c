/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:46:57 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/31 00:33:33 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_randnbr(int max, int amount)
{
	int		i;
	char	**nums;

	i = 0;
	nums = (char **)ft_calloc(amount + 1, sizeof(char *));
	while (i < amount)
	{
		nums[i] = ft_itoa(rand() % max);
		if (ft_dupnbr(nums) != 0)
			continue ;
		ft_putstr_fd(nums[i], 1);
		write(1, " ", 1);
		i++;
	}
	return (nums);
}
