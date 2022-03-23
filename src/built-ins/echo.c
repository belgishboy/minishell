/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:57:14 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/22 18:14:18 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	echo(char **array)
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
	if (nl)
		printf("\n");
}
