/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:04:10 by clems             #+#    #+#             */
/*   Updated: 2022/01/10 19:28:58 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a pointer to the first instance of c in the s, checking only n bytes
char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	*f;

	i = 0;
	f = (unsigned char *)str;
	while (f[i])
		i++;
	while (i >= 0)
	{
		if (f[i] == c)
			return ((char *)(f + i));
		i--;
	}
	return (NULL);
}
#include <stdio.h>
int main()
{
	char	string[] = "hvbjnk,imho.im";
	char	c = 'k';
	printf("%s\t%c\n%s\n", string,  c, ft_strrchr(string, c));
}
