/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:15:06 by clems             #+#    #+#             */
/*   Updated: 2021/05/28 14:47:58 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy n bytes from src to dest, stopping at c
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
		if (((unsigned char *)src)[i - 1] == (unsigned char)c)
			return (dest + i);
	}
	return (NULL);
}
//int main()
//{
//	char	*destination[20] = "00000000000000000000";
//	char	*source[] = "\\(^_^)/";
//	ft_memccpy(destination, source, '^', 10);
//	for(int i = 0; i < 20; i++)
//		write(1, &destination[i], 1);
//}
