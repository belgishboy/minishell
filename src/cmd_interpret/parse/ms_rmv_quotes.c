/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_rmv_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:11:17 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/25 11:11:20 by vheymans         ###   ########.fr       */
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
 * @param f [int] flag for freeing 
 * @return [char *] string with the quotes removed
*/
char	*rmv_quotes(char *s, int f)
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
	if (f == 1)
		free (s);
	return (new);
}
