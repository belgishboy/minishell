/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:50:26 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/23 16:59:08 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cd(char **array, t_shell *shell)
{
	char	*oldpwd;
	char	*newpwd;
	char	*check;

	check = NULL;
	check = getcwd(oldpwd, MAX_DIR);
	if (check != NULL)
		return (1);
	//function-call to update OLDPWD ft_update_oldpwd(oldpwd, shell);
	check = NULL;
	//do I have to close the dir as well?
	check = opendir(array[1]);
	if (check == NULL)
		return (1);
	check = NULL;
	check = getcwd(newpwd, MAX_DIR);
	if (check != NULL)
		return (1);
	//function-call to update PWD
}
