/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:15:22 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 12:56:23 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a string tha got his head and tail trimmed of 
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i[3];

	i[0] = 0;
	i[2] = ft_strlen((char *)s1);
	i[1] = i[2] - 1;
	while (ft_c_e_set_bonus(s1[i[0]], set) == 1)
	{
		i[2]--;
		i[0]++;
	}
	while (ft_c_e_set_bonus(s1[i[1]], set) == 1)
	{
		if (i[0] >= ft_strlen((char *)s1))
			break ;
		i[2]--;
		i[1]--;
	}
	if (i[2] == 0)
		i[2] = 1;
	res = ft_calloc((i[2] + 1), 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, &s1[i[0]], i[2] + 1);
	return (res);
}
//#include <stdio.h>
//int main()
//{
//	char	str[] = "3456inmmih,456789, fmkunk, l3456";
//	char	set[] = "1234567890";
//	printf("%s\t%s\n%s\n", str, set, ft_strtrim(str, set));
//}
