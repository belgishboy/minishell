/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:15:24 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/08 12:57:19 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * Main Shell Function
 * @param env [char **] envroment 
 * @return [int] 0 if successfull
*/
int	shell(char **env)
{
	t_shell	s;

	init_sig();
	s.env = create_env(env);
	err_num = 0;
	while (1)
	{
		s.input = readline(PROMPT);
		if (!s.input)
			break ;
		add_history(s.input);
		interpret(&s, &s.input);
		if (!extract_cmd(&s))
			launch_cmd(&s);
		free(s.input);
	}
	ms_exit(&s, NULL, 1);
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
		printf("error\n");//CLEMENS
		return (0);
	}
	shell(env);
	return (0);
}
