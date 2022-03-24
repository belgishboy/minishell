/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:50:54 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/24 17:37:03 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	arg_len(char *s)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			c = s[i];
			i ++;
			while (s[i] && s[i] != c)
			{
				i ++;
				count ++;
			}
		}
		else
			count ++;
		i ++;
	}
	return (count);
}

/**
 * @param s [char *] string from which quotes are to be removed
 * @return [char *] string with the quotes removed
*/
char	*rmv_quotes(char *s)
{
	int		i;
	int		x;
	char	*new;
	char	c;

	new = ft_calloc(arg_len(s) + 1, sizeof(char));
	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == D_Q || s[i] == S_Q)
		{
			c = s[i];
			i ++;
			while (s[i] && s[i] != c)
				new[x ++] = s[i ++];
		}
		else
			new[x ++] = s[i];
		i ++;
	}
	free (s);
	return (new);
}

int	count_args(char **split)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (split[i])
	{
		if (is_split(split[i][0]) != 3)
			count ++;
		i ++;
	}
	return (count);
}

/**
 * @param split [char **] char array to be worked on
 * @param seq	[t_seq *] sequance to be worked on
 * @return [int] 0 if succesful, 1 if malloc error
*/
int	arg_parsing(char **split, t_seq *seq)
{
	int	i;
	int	x;
	int	arg_cnt;

	arg_cnt = count_args(split);
	seq->cmd_args = ft_calloc(arg_cnt + 1, sizeof (char *));
	if (!seq->cmd_args[0])
		return (1);
	i = 0;
	x = 0;
	printf("[%d]\n", arg_cnt);//DELETE
	while (i < arg_cnt)
	{
		while (is_split(s[x][0]) == 3)
			x ++;
		seq->cmd_args[i] = rmv_quotes(s[x]);
		i ++;
		x ++;
	}
	return (0);
}

/**
 * @param seq [t_seq *] seq to be initilized
*/
void	init_seq(t_seq *seq)
{
	seq->split = NULL;
	seq->cmd_args = NULL;
	seq->fd[0] = STDIN_FILENO;
	seq->fd[1] = STDOUT_FILENO;
	seq->wht_cmd = -1;
	seq->nbr_arg = -1;
}

/**
 * initializes the sequence and parses the arguent to extract usefull args
 * @param sh [t_shell *] shell struct
 * @return 0 if successful, # of what seq[#] if fail
*/
int	parse(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->seq[i])
	{
		init_seq(sh->seq[i]);
		if (arg_parsing(sh->seq[i]->split, sh->seq[i]))
			return ((i + 1) * -1);
		i ++;
	}
	return (0);
}
