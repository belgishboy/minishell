/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:50:26 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/05 10:39:54 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	update_old(t_shell *shell)
{
	t_list	*old;
	t_list	*new;

	old = finder(shell->env, "OLDPWD");
	new = finder(shell->env, "PWD");
	free(((t_cont *)old->content)->value);
	((t_cont *)old->content)->value = \
		ft_strdup(((t_cont *)new->content)->value);
}

void	update_new(t_shell *shell, char *new_pwd)
{
	t_list	*new;

	new = finder(shell->env, "PWD");
	free(((t_cont *)new->content)->value);
	((t_cont *)old->content)->value = new_pwd;
}

void	cd(char **array, t_shell *shell)
{
	char	*oldpwd;
	char	*newpwd;
	char	*check;
	int		check_two;

	check_two = 0;
	check = NULL;
	check = getcwd(oldpwd, MAX_DIR);
	if (check == NULL)
		err_num = 1;
	update_OLD(shell);
//	check = opendir(array[1]);
	check_two = chdir(array[1]);
	else if (check_two)
		err_num = 1;
	check = NULL;
	check = getcwd(newpwd, MAX_DIR);
	else	if (check != NULL)
		err_num = 1;
}
