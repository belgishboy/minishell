/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:38:34 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/24 14:41:07 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**whitespace trims the white spaces off of a string
*/

#include "../../../inc/minishell.h"

/**
 * ft_white checks if 'c is a whitespace
 * @param c [char] char to be checked
 * @return [int] 1 if whitespace, 0 if not
*/
int	ft_white(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/**
 * is_whspace iterates through a line till it does not find a whitespace
 * @param s [char *] string being interated
 * @param dir [int] direction of intteration
 * @return [int] first postion that is not whitespace
*/
int	is_whspace(char *s, int dir)
{
	int	i;

	i = 0;
	if (dir < 0)
		i = ft_strlen(s) - 1;
	while (s[i] && i >= 0 && ft_white(s[i]))
	{
		i += dir;
	}
	if (dir < 0)
		i ++;
	return (i);
}

/**
 * trim_whitespace trims whitesspaces
 * @param s [char *] string being interated
 * @param dir [int] direction of interation,
 * if dir = 1 from the front, if -1 then from the back, if 2 then from both
 * @return [char *] returns a string with whitespace trimed
*/
char	*trim_whitespace(char *s, int dir)
{
	char	*trim;
	int		pos1;
	int		pos2;

	if (!s)
		return (NULL);
	if (dir > 0)
	{
		pos1 = is_whspace(s, 1);
		if (dir == 2)
			dir = -1;
	}
	else
		pos1 = 0;
	if (dir == -1)
		pos2 = is_whspace(s, -1);
	else
		pos2 = ft_strlen(s);
	if (pos2 <= pos1)
		return (""); //Return empty string if string only whitespace?
	trim = ft_substr(s, pos1, pos2 - pos1);
	free(s);
	return (trim);
}

/*int	main(int argc, char **argv)
{
	argc ++;
	int i = 1;
	while (argv[i])
		printf("[%d] before : [%s] :: after :[%s]\n\n", i, argv[i], trim_whitespace(argv[i++], -1));
	return (0);
}*/