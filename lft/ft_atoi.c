/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:40:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/12/08 17:58:01 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🌊
// Takes the initial portion of "str" and returns its integer value
int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && ((9 <= str[i] && str[i] <= 13) || str[i] == 32) != 0)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	char str1[] = "  -123";
// 	char str2[] = "  -2147483648";
// 	char str3[] = "4294967294";
// 	char str4[] = "-10000000000000000000";
// 	char str5[] = "  -12g3";
// 	char str6[] = "  -1-23";
// 	//the function breaks with inputs larger than 19/20ish numericons but thats
// 	//the edge of the edge and to be frank i don't know where or how atoi does
// 	//this
// 	//no one cares
// 	printf("%d\t%d\n%d\t%d\n%d\t%d\n%d\t%d\n%d\t%d\n%d\t%d\n", atoi(str1),
// 	ft_atoi(str1), atoi(str2), ft_atoi(str2), atoi(str3), ft_atoi(str3),
// 	 atoi(str4), ft_atoi(str4), atoi(str5), ft_atoi(str5), atoi(str6),
// 	 ft_atoi(str6));
// }
