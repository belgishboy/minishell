/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:15:24 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/31 02:55:15 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * Main Shell Function
 * 
*/
int		shell(char **env)
{
	t_shell	s;
	char *line;

	init_sig();
	s.env = create_env(env);
	err_num = 0;
	while (1)
	{
		line = readline("henneshell@vinnihamster$ ");
		interpret(&s, &line);
		//parsing
		//execution
		printf("%s\n", line);
		free(line);
		
	}
}

/**
 * Main Function
 * runs the shell function if # of args is 1 and that it is "./minishell".
 * Else returns error
 * @param argc	[int] number of arguments
 * @param argv	[char **] arguments
 * @param env	[char **] enviroment
 * @return 0 if succesfull, non-zero if error
*/
int	main(int argc, char **argv, char **env)
{
	err_num = 0;
	if (argc != 1 && strncmp(argv[0], "./minishell", strlen(argv[0])))
	{
		printf("error\n");
		return (0);
	}
	shell(env);
	return (0);
}
