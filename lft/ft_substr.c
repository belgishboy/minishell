/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:14:04 by clems             #+#    #+#             */
/*   Updated: 2021/12/09 12:05:57 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	lsub;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	else if ((size_t)((int)ft_strlen((char *)s) - start) > len)
		lsub = len;
	else
		lsub = (size_t)((int)ft_strlen((char *)s) - start);
	res = ft_calloc(lsub + 1, 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, &s[start], len);
	return (res);
}
#include <stdio.h>
int main()
{
	char	str[] = "123456789123456";
	printf("%s\t%s\n", str, ft_substr(str, 0, 1));
}
