/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_launch_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:59:28 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/05 15:42:31 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * 
*/
int	launch_cmd(t_shell *sh)
{
	int	tmp_fd[2];
	int	i;

	tmp_fd[0] = dup(0);
	tmp_fd[1] = dup(1);
	i = 0;
	while (sh->seq[i])
	{
		if (sh->seq[i]->fd[0] != 0)
			err_num = dup2(sh->seq[i]->fd[0], STDIN_FILENO);
		if (sh->seq[i]->fd[1] != 1)
			err_num = dup2(sh->seq[i]->fd[1], STDOUT_FILENO);
		if (err_num != 0)
			return (write(tmp_fd[1], "dup2 Top failed\n", 16));//CLEMENS
		ft_pipe(sh->seq[i]);
	}
	dup2(tmp_fd[0], STDIN_FILENO);
	dup2(tmp_fd[1], STDOUT_FILENO);
	close(tmp_fd[0]);
	close(tmp_fd[1]);
	return (0);
}
