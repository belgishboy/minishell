/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:59:34 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 11:53:45 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// sets n bytes of "s" to the value '\0'
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
//int main()
//{
//	char str7[11] = "1234567890";
//	char str8[11] = "678909jzun";
//	char str9[11] = "llOlOllOlO";
//	char str10[11] = "1234567890";
//	char str11[11] = "678909jzun";
//	char str12[11] = "llOlOllOlO";
//
//	printf("Yours   	%s\nOriginal	%s\n", str7, str10);
//	printf("Yours   	%s\nOriginal	%s\n", str8, str11);
//	printf("Yours   	%s\nOriginal	%s\n", str9, str12);
//
//	ft_bzero(str7,1);
//	ft_bzero(str8,4);
//	ft_bzero(str9,7);
//	bzero(str10,1);
//	bzero(str11,4);
//	bzero(str12,7);
//
//	write(1, "Yours   	", 9);
//	for (int a = 0; a < 10; a++)
//		write(1, &str7[a], 1);
//	write(1, "\nOriginal	", 10);
//	for (int a = 0; a < 10; a++)
//		write(1, &str10[a], 1);
//	write(1, "\nYours   	", 10);
//	for (int a = 0; a < 10; a++)
//		write(1, &str8[a], 1);
//	write(1, "\nOriginal	", 10);
//	for (int a = 0; a < 10; a++)
//		write(1, &str11[a], 1);
//	write(1, "\nYours   	", 10);
//	for (int a = 0; a < 10; a++)
//		write(1, &str9[a], 1);
//	write(1, "\nOriginal	", 10);
//	for (int a = 0; a < 10; a++)
//		write(1, &str12[a], 1);
//	write(1, "\n", 1);
//}
