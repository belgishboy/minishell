/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:11:31 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/24 15:49:54 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @param seq [t_seq *] seq to be initilized
*/
void	init_seq(t_seq *seq)
{
	seq->split = NULL;
	seq->cmd_args = NULL;
	seq->fd[0] = STDIN_FILENO;
	seq->fd[1] = STDOUT_FILENO;
	seq->wht_cmd = -1;
	seq->nbr_arg = -1;
}

/**
 * 
*/
int	extract_cmd(t_shell *sh)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (pipe_split(sh, sh->input, 0, 0))
		flag = -1;
	else
	{
		while (sh->seq[i])
		{
			init_seq(sh->seq[i]);
		}
		
	}
}