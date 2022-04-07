/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free_seq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:59:43 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/07 11:59:46 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	free_seq(t_seq *seq)// close the fd?
{
	if (seq->seq)
		free(seq->seq);
	if (seq->split[0])
		free_2dstr(seq->split);
	if (seq->path_cmd)
		free(seq->path_cmd);
	if (seq->cmd_args[0])
		free_2dstr(seq->cmd_args);
}

void	clean_seq(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->seq[i])
	{
		free_seq(sh->seq[i]);
		free(sh->seq[i]);
		i ++;
	}
	free(sh->seq);
}
