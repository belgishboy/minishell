/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:35:12 by clems             #+#    #+#             */
/*   Updated: 2022/01/10 19:30:31 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	compare the given inputs byte by byte returning 0 if they equal, and a 
//	number depending on which of them has a first instance that respectively
//	is bigger or less than the other
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (n - i > 0 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	return (0);
}
#include <stdio.h>
int	main()
{
	char	satz1[50] = "something in the path=";
	char	satz2[50] = "something in the path";
	int i = ft_strncmp(satz1, satz2, ft_strlen(satz2));
	printf("%s\n%s\n%d\n", satz1, satz2, i);
}
