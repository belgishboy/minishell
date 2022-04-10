/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:11:31 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/09 15:33:27 by jscheuma         ###   ########.fr       */
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
	return (flag);
}
