/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:57:14 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/31 03:32:38 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ms_echo(char **array)
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
}
