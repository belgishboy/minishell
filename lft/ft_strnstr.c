/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s1ns1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1921/05/12 15:01:44 by clems             #+#    #+#             */
/*   Updated: 2021/06/04 17:26:08 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a pointer to the first matching instance of s2 in s1
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (*(s1 + i) && i < n)
	{
		a = 0;
		while (*(s2 + a) && *(s1 + i + a)
			&& *(s2 + a) == *(s1 + i + a) && a < n - i)
			a++;
		if (!*(s2 + a))
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
//#include <stdio.h>
//#include <bsd/string.h>
//int main()
//{
//	char	haystack[] = "lorem ipsum dolor sit amet";
//	char	needle[]	= "ipsum";
//	int		i = 11;
//	printf("%s\t%s\n%s\n", haystack, needle, ft_strnstr(haystack, needle, i));
//	printf("%s\t%s\n%s\n", haystack, needle, strnstr(haystack, needle, i));
//}
