/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:11:31 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/30 18:30:06 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * 
*/
int	extract_cmd(t_shell *sh)
{
	printf("extracting cmds\n");
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (pipe_split(sh, sh->input, 0, 0))
		flag = -1;
	else
		parse(sh);
	printf("done extracting cmds\n");
	return (0);
}

int	main(void)
{
	t_shell	*sh = malloc(sizeof(t_shell));
	int	i = 1;

	while (1)
	{
		sh->input = readline(PROMT);
		if (ft_strncmp(sh->input, "EXIT", 4) == 0)
			break ;
		extract_cmd(sh);
		printf("\nDONE %d\n\n", i);
		i ++;
	}
	return (0);
}