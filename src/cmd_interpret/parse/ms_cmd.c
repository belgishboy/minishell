/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:47:08 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/30 18:23:00 by vheymans         ###   ########.fr       */
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

char	**ft_path(void)
{
	char	**path;

	path = ft_split(getenv("PATH="), ':');
	if (!path)
		return (NULL);
	ft_add_slash(path);
	return (path);
}

/*
**Make a new element of t_cmd type
*/

/*int	cmd_new(t_seq *s, char **path)// need to take out quotes and spaces 
{
	arg_parsing(s->split, s);
	printf("done arg parsing\n");
	if (s->cmd_args == 0)
		return (1);
	for(int i = 0; s->cmd_args[i]; i ++)
		printf("[%d] : [%s]\n", i , s->cmd_args[i]);
	if (s->wht_cmd > 0)
		s->path_cmd = NULL;
	else
	{
		s->path_cmd = ft_get_path(path, s->cmd_args);
		if (s->path_cmd == 0)
			return (1);
	}
	printf("path_cmd = %s\n", s->path_cmd);
	return (0);
}*/

// t_cmd	*cmd_line(int n_cmds, char **argv, char **path)
// {
// 	t_cmd	*cmd_line;
// 	int		x;

// 	x = 0;
// 	cmd_line = (t_cmd *)malloc(n_cmds * sizeof(t_cmd));
// 	if (!cmd_line)
// 		return (NULL);
// 	while (x < n_cmds)
// 	{
// 		if (cmd_new(&cmd_line[x], argv[x + 2], path))
// 		{
// 			free_cmd(cmd_line, x);
// 			free(cmd_line);
// 			free_2dstr(path);
// 			return (NULL);
// 		}
// 		x ++;
// 	}
// 	return (cmd_line);
// }
