/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:47:57 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/11 11:34:36 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	fd_infile(t_seq *seq, char *arg)
{
	char	*file;

	if (arg[1] == '<')
		return (0);
	else
	{
		file = trm_whtsp(&arg[1], 1);
		if (seq->fd[0] != 0)
			close(seq->fd[0]);
		if (!access(file, F_OK))
			seq->fd[0] = open(file, O_RDWR, 0777);
		else
		{
			ms_error(access(file, F_OK), ft_strdup(""),
				"\b\bno such file or directory\n", 1);
			return (1);
		}
	}
	if (file)
		free(file);
	return (0);
}

int	fd_outfile(t_seq *seq, char *arg)
{
	char	*file;

	if (seq->fd[1] != 1)
		close(seq->fd[1]);
	if (arg[1] == '>')
	{
		file = trm_whtsp(&arg[2], 1);
		seq->fd[1] = open(file, O_RDWR | O_APPEND | O_CREAT | O_CLOEXEC, 0777);
	}
	else
	{
		file = trm_whtsp(&arg[1], 1);
		seq->fd[1] = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	}
	if (file)
		free(file);
	return (0);
}

/**
 * @param seq [t_seq *] seq being operated on
 * @param sp [char **] arg split being operated on
 * @return [int] 0 if successful, 1 if unable to open an input fd
*/
int	init_fd(t_seq *seq, char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		if (sp[i][0] == '<')
		{
			if (fd_infile(seq, sp[i]))
				return (1);
		}
		else if (sp[i][0] == '>')
		{
			if (fd_outfile(seq, sp[i]))
				return (1);
		}
		i ++;
	}
	return (0);
}
