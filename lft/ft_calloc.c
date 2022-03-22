/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:34:13 by clems             #+#    #+#             */
/*   Updated: 2021/12/08 18:01:10 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// allocate memory that consists only of '\0' bytes
//	if (!nb || !size || nmemb * n > sizeof(int))
//		return (NULL);
//		↑ cases which are in the manual but molinette failed me for some reason
void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*dest;
	int		l;
	int		i;

	l = nmemb * n;
	dest = malloc(l);
	if (!dest)
		return (0);
	i = 0;
	while (i < l)
	{
		((unsigned char*)dest)[i] = 0;
		i++;
	}
	return (dest);
}
