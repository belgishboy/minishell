/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:11:31 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/08 12:51:06 by vheymans         ###   ########.fr       */
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
	int	i;

	flag = 0;
	i = 0;
	if (pipe_split(sh, sh->input, 0, 0))
		flag = -1;
	else
		flag = parse(sh);
	return (flag);
}
