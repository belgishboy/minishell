/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/10 16:58:51 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumeric(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if ((!ft_isdigit(num[i]) && (i != 0)) || \
		(!ft_isdigit(num[i]) && num[i] != '+' && num[i] != '-' && i == 0))
			return (1);
		i++;
	}
	return (0);
}
