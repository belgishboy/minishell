/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free_seq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:59:43 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/07 12:10:25 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/**
 * @brief free the inside of each t_seq.
 * 	checks if char *seq exist and frees if it does.
 * 	checks if seq->split[0] exist and frees if it does. If not, free seq->split.
 * 	checks if char *path_cmd exist and frees if it does.
 * 	checks if seq->cmd_args[0] exist and frees if it does. If not, free seq->cmd.
 * @param seq [t_seq *] seq struct to be freed
 * @return [void]
*/
void	free_seq(t_seq *seq)// close the fd?
{
	if (seq->seq)
		free(seq->seq);
	if (seq->split[0])
		free_2dstr(seq->split);
	else if (seq->split)
		free(seq->split);
	if (seq->path_cmd)
		free(seq->path_cmd);
	if (seq->cmd_args[0])
		free_2dstr(seq->cmd_args);
	else if (seq->cmd_args)
		free(seq->cmd_args);
}

/**
 * clean_seq frees each of the t_seq and then frees the double pointer
 * @param sh [t_shell *] Shell struct
 * @return [void]
*/
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
