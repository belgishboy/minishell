/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:43:10 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/10 17:14:59 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_pipe_last(t_shell *sh, t_seq *seq, int s_fd[2], int status)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
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
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_errnum = WEXITSTATUS(status);
		ms_exec_builtins(sh, seq, pid);
		close(fd[0]);
	}
}

void	ft_pipe(t_shell *sh, t_seq *seq, int status)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
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
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_errnum = WEXITSTATUS(status);
		ms_exec_builtins(sh, seq, pid);
		close(fd[0]);
	}
}
