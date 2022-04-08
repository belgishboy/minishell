/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:59:53 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/05 13:59:53 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief join two strings, with the second one being inserted into the first 
 * 			at a position and replacing an amount of characters
 * @param line [char*] base string later freed
 * @param add	[char*] inserted string
 * @param pos [int] starting position of the insertion
 * @param skipc [int] number of chars to be replaced
*/
char	*insert_string(char *line, char *add, int pos, int skipc)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_calloc(ft_strlen(line) + ft_strlen(add) + 10, sizeof(char));
	while (i < pos)
	{
		new[i] = line[i];
		i++;
	}
	i = 0;
	while (add && add[i])
	{
		new[i + pos] = add[i];
		i++;
	}
	i = pos + skipc - 1;
	while (line[i])
	{
		new[ft_strlen(new)] = line[i];
		i++;
	}
	free(line);
	return (new);
}


int	extract_rep(char *line, t_list *env, char **replace)
{
	int		i;
	char	*key;
	t_list	*envar;

	i = 0;
	if (line[0] == '?')
		*replace = ft_itoa(((unsigned short)err_num % 256));
	if (line[0] == '0')
		*replace = ft_strdup("minishell");
	if (line[0] == '0' || line[0] == '?')
		return (2);
	if (!ft_isalpha(line[0]) && line[0] != '_')
	{
		*replace = ft_strdup("");
		return (0);
	}
	while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
		i++;
	key = malloc((i + 1) * sizeof(char));
	ft_strlcpy(key, line, i);
	envar = finder(env, key);
	free(key);
	*replace = ft_strdup(((t_cont *)envar->content)->value);
	return (i);
}

/**
 * @brief edit the given string and replace indicators of
 * 			variables with the value of the variable
 * @param s [t_shell*] our shell
 * @param line [char**] address of the given line, for reallocation
 * @return [void]
*/
void	interpret(t_shell *s, char **line)
{
	int		i;
	int		state;
	int		keylen;
	char	*replacement;

	i = 0;
	state = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\'')
		{
			if (state == 0)
				state = 1;
			else
				state = 0;
		}
		if ((*line)[i] == '$' && state == 0)
		{
			keylen = extract_rep(&(*line)[i + 1], s->env, &replacement);
			(*line) = insert_string((*line), replacement, i, keylen + 2);
			i += ft_strlen(replacement);
			free(replacement);
		}
		i++;
	}
}

// // gcc built-ins/export.c built-ins/env.c built-ins/unset.c 
// // cmd_interpret/vars.c ../lft/libft.a && ./a.out
// int main(int argc, char **argv, char **env)
// {
// 	if (argc == 1000 || !argv[0])
// 		return (1110);
// 	printf("%i\b", argc);

// 	t_shell s;
// 	s.env = create_env(env);
// 	ms_env(&s);
// 	printf("created \n\n\n");
// 	err_num = 42;
// 	char	*line = ft_strdup("'lal$USER###'##");
// 	printf("%s\n", line);
// 	interpret(&s, &line);
// 	printf("%s\n", line);
// 	return (0);
// }
