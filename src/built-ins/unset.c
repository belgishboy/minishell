/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:08:04 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/05 15:08:05 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	keyerror(char *input)
{
	int	i;

	i = 0;
	if (!ft_isalpha(input[i]) && input[i] != '_')
		return (1);
	while (input[i] && input[i] != '=')
	{
		if (!ft_isalnum(input[i]) && input[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	ms_unset(t_shell *s, t_seq *q, pid_t pid)
{
	t_list	*new;
	t_list	*tmp;
	int		i;

	i = 1;
	while (q->cmd_args[i])
	{
		new = finder(s->env, q->cmd_args[i]);
		if ((keyerror(q->cmd_args[i]) || ft_strchr(q->cmd_args[i], '=')) && !pid)
			printf("minishell: unset: `%s\': invalid\n", q->cmd_args[i]);
		else if (new)
		{
			tmp = s->env;
			if (tmp == new)
				s->env = tmp->next;
			else
			{
				while (tmp->next != new)
					tmp = tmp->next;
				tmp->next = new->next;
			}
			delvar(new);
		}
		i++;
	}
}
