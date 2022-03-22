/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:40:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/05/27 11:55:38 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check if the given char is alphanumerical
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
		return (8);
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
//	printf("%c\t%d\t%d\n", chars[i], isalnum(chars[i]), ft_isalnum(chars[i]));
//	i++;
//	}
//}
