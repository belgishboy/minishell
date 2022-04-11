/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:11:31 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/11 10:04:10 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * does all of the extracting
 * @param sh [t_shell *] shell
 * @return [int] 0 if successful, something else
*/
int	extract_cmd(t_shell *sh)
{
	int	flag;

	flag = 0;
	if (pipe_split(sh, sh->input, 0, 0))
		flag = -1;
	else
		flag = parse(sh, 0);
	if (flag > 0)
	{
		clean_seq(sh);
		close_fd();
	}
	return (flag);
}
