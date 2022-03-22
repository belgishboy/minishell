/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:46:12 by clems             #+#    #+#             */
/*   Updated: 2021/06/04 15:39:44 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy n bytes from src to dest and return dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
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
