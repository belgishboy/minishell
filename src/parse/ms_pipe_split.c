/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:36:20 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/22 18:25:14 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Handles all the spliting between pipes of the input 
*/

#include "../../inc/minishell.h"

/**
 * returns the pos in string where the quote's end
 * @param pos [int] pos of the start of the quote
 * @param c [char] if double or single quotes
 * @param in [char *] string being checked
 * @return [int] pos of end of quote
*/
int	pipe_quote(int pos, char c, char *in)
{
	while (in[pos] && in[pos] != c)
		pos++;
	return (pos);
}

/**
 * count_pipe returns the number of pipes and therefor splits needed
 * @param in [char *] string input
 * @return [int] number of splits needed
*/
int	count_pipe(char *in)// what if it ends with a pipe == missing bash cmd; triple |||?
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (in[i])
	{
		if (in[i] == D_Q || in[i] == S_Q)
			i = pipe_quote(i + 1, in[i], in);
		if (in[i] == PIPE)
		{
			if (in[i + 1] != PIPE)
				count ++;
			if (in[i + 1] && in[i + 1] == PIPE)
				return (-1);
		}
		i ++;
	}
	return (count);
}

/**
 * pipe_splits splits `in` by pipes
 * @param shell [t_shell *] shell struct
 * @param in [char *] input string
 * @param pos1 [int] because I have too many lines
 * @param pos2 [int] because I have too many lines
 * @return 1 if error in pipe count, 0 if succes
*/
int	pipe_split(t_shell *shell, char *in, int pos1, int pos2)
{
	int	n_pipes;

	shell->n_cmds = count_pipe(in);
	if (shell->n_cmds < 1)
		return (1);
	shell->seq = malloc(shell->n_cmds * sizeof(t_seq *));
	n_pipes = 0;
	while (n_pipes < shell->n_cmds)
	{
		while (in[pos2] && in[pos2] != PIPE)
		{
			if (in[pos2] == D_Q || in[pos2] == S_Q)
				pos2 = pipe_quote(pos2, in[pos2], in);
			pos2 ++;
		}
		if (!in[pos2] || in[pos2 + 1] != PIPE)
		{
			shell->seq[n_pipes] = malloc(sizeof(t_seq));
			shell->seq[n_pipes ++]->seq = ft_substr(in, pos1, pos2 - pos1);
			pos1 = ++ pos2;
		}
		while (in[pos2] == PIPE && in[pos2])
			pos2 ++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	argc ++;
	t_shell *s = malloc(sizeof(t_shell *) * 1);
	pipe_split(s, argv[1], 0, 0);
	int i = 0;
	while (i < s->n_cmds)
	{
		printf("%d] %s\n", i + 1, s->seq[i]->seq);
		i ++;
	}
	return (0);
}
