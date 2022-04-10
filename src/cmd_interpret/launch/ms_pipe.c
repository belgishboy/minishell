/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:43:10 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/10 16:19:14 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_pipe_last(t_shell *sh, t_seq *seq, int s_fd[2])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd))
		write(2, "Pipe Falure\n", 12); //CLEMENS
	pid = fork();
	if (pid < 0)
		write(2, "The Fork failed\n", 16);
	if (!pid)
	{
		close(fd[0]);
		if (dup2(s_fd[1], STDOUT_FILENO) == -1)
			write(1, "dup2 Child failed\n", 18);
		ms_exec_builtins(sh, seq, pid);
		exit(127);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			write(1, "dup2 Parent failed\n", 19);
		waitpid(pid, NULL, 0);
		ms_exec_builtins(sh, seq, pid);
		close(fd[0]);
	}
}

void	ft_pipe(t_shell *sh, t_seq *seq)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd))
		write(2, "Pipe Falure\n", 12); //CLEMENS
	pid = fork();
	if (pid < 0)
		write(2, "The Fork failed\n", 16);
	if (!pid)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			write(1, "dup2 Child failed\n", 18);
		ms_exec_builtins(sh, seq, pid);
		exit(127);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			write(1, "dup2 Parent failed\n", 19);
		waitpid(pid, NULL, 0);
		ms_exec_builtins(sh, seq, pid);
		close(fd[0]);
	}
}
