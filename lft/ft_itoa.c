/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:34:14 by clems             #+#    #+#             */
/*   Updated: 2021/08/31 00:17:43 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// convert the given positive integral number to a char representation in *res
static void	pitoa (long m, int p, int l, char *res)
{
	int	i;
	int	d;

	i = 0;
	d = 1;
	while (i < l - 1)
	{
		d *= 10;
		i++;
	}
	i = 0;
	while (i < l)
	{
		res[i + p] = (m / d) + 48;
		m %= d;
		d /= 10;
		i++;
	}
	res[i + p] = '\0';
}

// check for edge cases and execute the helper function with positive input
char	*ft_itoa(int n)
{
	long	m;
	int		p;
	int		l;
	char	*res;

	m = (long)n;
	p = 0;
	if (m < 0)
		p = 1;
	if (p == 1)
		m *= -1;
	l = ft_log(m, 10);
	res = malloc(l + p + 1);
	if (res == NULL)
		return (NULL);
	if (p == 1)
		res[0] = '-';
	pitoa(m, p, l, res);
	return (res);
}
//#include <stdio.h>
//int main()
//{
//	int test = 2147483648;
//	printf("int\tto\tascii\n");
//	printf("%d\t\t%s\n", test, ft_itoa(test));
//}
