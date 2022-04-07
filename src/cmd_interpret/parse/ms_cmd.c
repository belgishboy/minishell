/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:47:08 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/07 12:26:05 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*ft_get_path( char **cmd, char **path)
{
	int		x;
	char	*temp;

	x = 0;
	while (path[x])
	{
		temp = ft_strjoin(path[x], *cmd);
		if (!access(temp, X_OK) && !access(temp, F_OK))
			return (temp);
		free(temp);
		x ++;
	}
	return (NULL);
}

/*
**adds a '/' to the end of line in a array
*/

int	ft_add_slash(char **array)
{
	int		x;
	char	*temp;

	x = 0;
	while (array[x])
	{
		temp = ft_strjoin(array[x], "/");
		free(array[x]);
		array[x] = temp;
		x ++;
	}
	return (0);
}
/*
**Creates the 2d array containing all the possible paths
*/

char	**ft_path(t_shell *s)
{
	char	**path;
	t_list	*pth;

	pth = finder(s->env, "PATH=");
	path = ft_split(((t_cont*)pth->content)->value, ':');
	if (!path)
		return (NULL);
	ft_add_slash(path);
	return (path);
}
