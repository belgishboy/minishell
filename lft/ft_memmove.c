/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:53:08 by clems             #+#    #+#             */
/*   Updated: 2021/05/30 12:38:48 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy n bytes from src to dest and return dest while protecting against
// overlapping memory of src and dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
		return (NULL);
	if ((size_t)src > (size_t)dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}
//#include <stdio.h>
//int main()
//{
//	char	*destination;
//	destination = malloc(100 * sizeof(char));
//	ft_memset(destination, 'l', 100);
//	char	source[] = "100101001001001010111101010101";
//	destination = (char *)ft_memcpy(destination, source, sizeof(char) * 20);
//	printf("%s\n", destination);
//}
