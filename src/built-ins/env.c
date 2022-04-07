/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:09:28 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/05 15:09:29 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cont	*envar(char *p_var)
{
	int		i;
	char	*eq;
	t_cont	*var;

	var = malloc(sizeof(t_cont));
	eq = ft_strchr(p_var, '=');
	if (eq)
	{
		i = ft_strlen(p_var) - ft_strlen(eq);
		var->key = malloc(i * sizeof(char));
		ft_strlcpy(var->key, p_var, i + 1);
		var->value = ft_strdup(p_var + i + 1);
	}
	else
	{
		var->key = ft_strdup(p_var);
		var->value = ft_strdup("");
	}
	return (var);
}

void	delvar(t_list *elem)
{
	t_cont	*var;

	if (elem)
	{
		var = elem->content;
		if (var)
		{
			if (var->key)
				free(var->key);
			if (var->value)
				free(var->value);
			free(var);
		}
		free(elem);
	}
}

t_list	*create_env(char **p_env)
{
	int		i;
	t_list	*env;

	if (!p_env[0])
		return (NULL);
	env = ft_lstnew((void *)envar(p_env[1]));
	i = 2;
	while (p_env[i])
	{
		ft_lstadd_back(&env, ft_lstnew(envar(p_env[i])));
		i++;
	}
	return (env);
}

void	ms_env(t_shell *s, t_seq *q, pid_t pid)
{
	t_list	*temp;

	if (q->cmd_args[1] && !pid)
	{
		printf("env: %s: we don't take arguments\n", q->cmd_args[1]);
		err_num = 127;
		return ;
	}
	temp = s->env;
	while (temp)
	{
		if (((t_cont *)temp->content)->value[0] && !pid)
			printf("%s=%s\n", ((t_cont *)temp->content)->key, \
							((t_cont *)temp->content)->value);
		temp = temp->next;
	}
	err_num = 0;
}

char	**env_copy(t_list *p_env)
{
	char	**env;
	t_list	*temp;
	int		i;

	temp = p_env;
	i = 0;
	env = ft_calloc((ft_lstsize(p_env) + 1), sizeof(char *));
	while (i < ft_lstsize(p_env))
	{
		env[i] = ft_calloc(ft_strlen(((t_cont *)temp->content)->key) + \
							ft_strlen(((t_cont *)temp->content)->value) + 2, 1);
		ft_strlcpy(env[i], ((t_cont *)temp->content)->key, \
							ft_strlen(((t_cont *)temp->content)->key) + 1);
		env[i][ft_strlen(env[i])] = '=';
		ft_strlcpy(env[i] + ft_strlen(env[i]), ((t_cont *)temp->content)->\
								value, ft_strlen(((t_cont *)temp->content)->\
																value) + 1);
		temp = temp->next;
		i++;
	}
	return (env);
}

// // gcc env.c ../../lft/libft.a && ./a.out
// int main(int argc, char **argv, char **env)
// {
// 	if (argc == 1000 || !argv[0])
// 		return (1110);
// 	printf("%i\b", argc);

// 	t_shell s;
// 	s.env = create_env(env);
// 	ms_env(&s);
// 	printf("\n\n\n");
// 	char **copy = env_copy(s.env);
// 	for (int i = 0; copy[i]; i++)
// 	{
// 		printf("copy:%s\n", copy[i]);
// 		free (copy[i]);
// 	}
// 	free(copy);
// 	return (0);
// }
