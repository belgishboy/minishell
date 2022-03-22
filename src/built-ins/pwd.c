/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:30:27 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/22 17:50:00 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pwd(t_list *env)
{
	char	path[MAX_PATH];
	char	*check;

	check = NULL;
	check = getcwd(path, MAX_PATH);
	if (!check)
		return (1);
	printf("%s\n", path);
	return (0);
}
