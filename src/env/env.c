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
	var->p = 1;
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
		free(elem)
	}
}

t_list	*create_env(char **p_env)
{
	int		i;
	t_list	*env;

	if (!env || !p_env[0])
		return (NULL);
	env = ft_lstnew((void *)envar(p_env[1]));
	i = 1;
	while (p_env[i])
	{
		ft_lstadd_back(&env, ft_lstnew(envar(p_env[i])));
		i++;
	}
	return (env);
}

void	ms_env(t_shell *s)
{
	t_list	*temp;

	temp = s->env;
	while (temp)
	{
		if (((t_cont *)temp->content)->p == 1)
			printf("%s=%s\n", ((t_cont *)temp->content)->key, ((t_cont *)temp->content)->value);
		if (((t_cont *)temp->content)->p == -1)
			printf("%s=\n", ((t_cont *)temp->content)->key);
		temp = temp->next;
	}
}
// gcc env.c ../../lft/libft.a && ./a.out
int main(int argc, char **argv, char **env)
{
	if (argc == 1000 || !argv[0])
		return (1110);
	printf("%i\b", argc);

	t_shell s;
	s.env = create_env(env);
	ms_env(&s);
}