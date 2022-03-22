/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:40:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/05/27 11:58:09 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🌊

// check if the given char is printable
int	ft_isprint(int c)
{
	if ((32 <= c) && (c <= 126))
		return (16384);
	return (0);
}
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//int main()
//{
//	char	chars[] = "15äh🌊rza}";
//	size_t	i = 0;
//	printf("char\torg\tme\n");
//	while (i < strlen(chars))
//	{
//	printf("%c\t%d\t%d\n", chars[i], isprint(chars[i]), ft_isprint(chars[i]));
//	i++;
//	}
//}
