/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:04:00 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 12:29:36 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// append src to dst up to size, but return src + dst? this is confusing, ('~')
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	k;
	size_t	i;

	l = 0;
	k = 0;
	i = ft_strlen(dst);
	if (ft_strlen(dst) >= size)
		return (ft_strlen((char *)src) + size);
	while (dst[l])
		l++;
	while (src[k] && (l < (size - 1)))
	{
		dst[l] = src[k];
		l++;
		k++;
	}
	dst[l] = '\0';
	return (i + ft_strlen((char *)src));
}
//#include <stdio.h>
//int main()
//{
//	char	dest[100] = "append here ->";
//	char	src[] = "<- ereh dneppa";
//ft_strlcat(dest, src, (ft_strlen(src) + ft_strlen(dest) + 1) * sizeof(char));
//	printf("%s\n", dest);
//}
