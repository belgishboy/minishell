/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:15:46 by clems             #+#    #+#             */
/*   Updated: 2021/05/29 17:03:37 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// set n bytes of src to the value of c
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}
//#include <stdio.h>
//int main()
//{
//	char	*destination;
//	destination = malloc(100 * sizeof(char));
//	ft_memset(destination, '4', 100);
//	printf("%s\n", destination);
//	ft_memset(destination, '2', 100);
//	printf("%s\n", destination);
//}
