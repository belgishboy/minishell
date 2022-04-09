/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:57:14 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/08 19:10:46 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ms_echo(char **array, pid_t pid)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!array[1] && !pid)
	{
		printf("\n");
		return ;
	}
	if (ft_strlen(array[1]) == 2 && !ft_strncmp(array[1], "-n", 2))
	{
		flag++;
		i++;
	}
	while (array[i] && !pid)
	{
		printf("%s ", array[i]);
		i++;
	}
	if (!pid)
		printf("\b");
	if (!flag && !pid)
		printf("\n");
	err_num = 0;
}

/*void	ms_echo(char **array)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	if (ft_strncmp(array[i], "-n", ft_strlen(array[i])))
	{
		nl = 0;
		i++;
	}
	while (array[i])
	{
		printf("%s ", array[i]);
		i++;
	}
	printf("\b");
	if (nl)
		printf("\n");
}*/
