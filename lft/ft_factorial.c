/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:56:49 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/09/10 12:06:35 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_factorial(size_t n)
{
	size_t res;

	res = 1;
	if (n > 1)
		res = res * n * ft_factorial(n - 1);
	return (res);
}

// int main()
// {
// 	int nbr = 0;
// 	printf("number :\t%d\nresult :\t%d", nbr, (int)ft_factorial(nbr));
// }
