/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:30:27 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/10 17:21:13 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief display the current working directory
 * @param pid [pid_t]	child-or-not pid
*/
void	pwd(pid_t pid)
{
	char	path[MAX_PATH];
	char	*check;

	check = NULL;
	check = getcwd(path, MAX_PATH);
	if (!check)
		return ;
	if (!pid)
		printf("%s\n", path);
	g_errnum = 0;
}
