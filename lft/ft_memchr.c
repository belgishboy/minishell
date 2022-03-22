/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:08:51 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 12:04:27 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a pointer to the first instance of c in the s, checking only n bytes
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
//int main()
//{
//	char	satz[] = "abcdefghijklmnopqrstuvwxyz0123456789";
//	char	*pc;
//	char	c = 'h';
//	pc = ft_memchr(satz, c, 36);
//	write(1, &c, 1);
//	write(1, "\t", 1);
//	write(1, pc, 10);
//	//in the test i write 10 chars from the result onwars to prove the first 
//	// one was found. if this leads to a seg fault in testing the function
//	// is not stupid, the tester is ,_,
//	// or i am for not using printf instead ♥
//}
