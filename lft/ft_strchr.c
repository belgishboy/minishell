/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:41:01 by clems             #+#    #+#             */
/*   Updated: 2021/08/31 00:00:30 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a pointer to the first instance of c in str
char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	*f;

	f = (unsigned char *)str;
	i = 0;
	while (f[i])
	{
		if (f[i] == c)
			return ((char *)(f + i));
		i++;
	}
	if (f[i] == c)
		return ((char *)(f + i));
	return (NULL);
}
//int main()
//{
//		char	satz[] = "abcdefghijklmnopqrstuvwxyz0123456789";
//	char	*pc;
//	char	c = 'h';
//	pc = ft_strchr(satz, c, 36);
//	write(1, &c, 1);
//	write(1, "\t", 1);
//	write(1, pc, 10);
//	/*
//	in the test i write 10 chars from the result onwars to prove the first 
//	one was found. if this leads to a seg fault in testing the function
//	is not stupid, the tester is ,_,
//	or i am for not using printf lol
//	*/
//}
