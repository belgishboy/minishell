/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:36:14 by clems             #+#    #+#             */
/*   Updated: 2021/06/01 09:38:21 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	compare the given inputs byte by byte returning 0 if they equal, and a 
//	number depending on which of them has a first instance that respectively
//	is bigger or less than the other
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
//#include <stdio.h>
//int	main()
//{
//	char	satz1[50] = "running out of things to write";
//	char	satz2[50] = "running out of things to write";
//	int i = ft_memcmp(satz1, satz2, 42);
//	printf("%s\n%s\n%d\n", satz1, satz2, i);
//}
