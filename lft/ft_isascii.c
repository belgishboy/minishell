/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:40:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/05/29 16:23:17 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🌊

// check if the given character is included in the
// American Standard Code for Information Interchange (ASCII)
int	ft_isascii(int c)
{
	if ((0 <= c) && (c <= 127))
		return (1);
	return (0);
}
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//int main()
//{
//	char	chars[] = "15ährza}";
//	size_t	i = 0;
//	printf("char\torg\tme\n");
//	while (i < strlen(chars))
//	{
//	printf("%c\t%d\t%d\n", chars[i], isascii(chars[i]), ft_isascii(chars[i]));
//	i++;
//	}
//}
