/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:30:27 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/05 13:40:54 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
	err_num = 0;
	return ;
}
