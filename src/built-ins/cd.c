/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:50:26 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/29 02:29:57 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	update_OLD(t_shell *shell)
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

	check = NULL;
	check = getcwd(oldpwd, MAX_DIR);
	if (check != NULL)
		return (1);
	update_OLD(shell);
	// is this a leak? line 49
	check = NULL;
	//do I have to close the dir as well?
	check = opendir(array[1]);
	if (check == NULL)
		return (1);
	check = NULL;
	check = getcwd(newpwd, MAX_DIR);
	if (check != NULL)
		return (1);
	
}
