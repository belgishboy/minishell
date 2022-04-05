/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:47:57 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/03 17:12:19 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

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
			if (seq->fd[0] != 0)
				close(seq->fd[0]);
			if (!access(sp[i], F_OK))
				seq->fd[0] = open(&sp[i][1], O_RDONLY, 0777);
			else
				return (1);
		}
		else if (sp[i][0] == '>')
		{
			seq->fd[1] = open(&sp[i][1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (seq->fd[1] != 1)
				close(seq->fd[1]);
		}
		i ++;
	}
	return (0);
}
