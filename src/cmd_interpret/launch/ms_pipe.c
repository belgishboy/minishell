/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:43:10 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/05 15:48:33 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_pipe(t_seq *seq, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd))
		ft_error("Pipe Falure", STDERR_FILENO);
	pid = fork();
	if (pid < 0)
		ft_error("The Fork failed", STDERR_FILENO);
	if (!pid)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 Child failed", STDERR_FILENO);
		execve(seq->path_cmd, seq->cmd_args, env);
		exit(127);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error("dup2 Parent failed", STDERR_FILENO);
		waitpid(pid, NULL, 0);
		close(fd[0]);
	}
}