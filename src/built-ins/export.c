#include "../../inc/minishell.h"

void	sort_list(char ***plist, int n)
{
	int		i[2];
	char	*tmp;
	char	**list;

	list = *plist;
	i[0] = 0;
	i[1] = 0;
	while (i[0] < n && list[i[0]] && list[i[0] + 1])
	{
		if (list[i[0]][i[1]] == list[i[0] + 1][i[1]])
			i[1]++;
		else if (list[i[0]][i[1]] < list[i[0] + 1][i[1]])
		{
			i[0]++;
			i[1] = 0;
		}
		else if (list[i[0]][i[1]] > list[i[0] + 1][i[1]])
		{
			tmp = list[i[0]];
			list[i[0]] = list[i[0] + 1];
			list[i[0] + 1] = tmp;
			i[0] = 0;
			i[1] = 0;
		}
	}
}

void	del_list(char **list)
{
	int	i;

	i = 0;
	while (list && list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

int	export_all(t_list *env)
{
	char	**c_env;
	int		i;
	char	*tmp;

	c_env = env_copy(env);
	sort_list(&c_env, ft_lstsize(env));
	i = 0;
	while (c_env[i])
	{
		c_env[i] = ft_realloc(c_env[i], ft_strlen(c_env[i]), 3);
		if (!ft_strchr(c_env[i], '='))
			printf("declare -x %s\"\"\n", c_env[i]);
		else
		{
			tmp = ft_strchr(c_env[i], '=');
			ft_memmove(tmp + 1, tmp, ft_strlen(tmp));
			*tmp = '=';
			*(tmp + 1) = '"';
			c_env[i][ft_strlen(c_env[i])] = '"';
			printf("declare -x %s\n", c_env[i]);
		}
		i++;
	}
	del_list(c_env);
	return (0);
}

t_list	*finder(t_list *env, char *key)
{
	t_list	*temp;
	int		klen;

	if (ft_strchr(key, '='))
		klen = ft_strlen(key) - ft_strlen(ft_strchr(key, '='));
	else
		klen = ft_strlen(key);
	temp = env;
	while (temp)
	{
		if (!ft_strncmp(key, ((t_cont *)temp->content)->key, klen))
		{
			break ;
		}
		temp = temp->next;
	}
	return (temp);
}

int	ms_export(t_shell *s, t_seq *q)
{
	t_list	*new;
	int		i;

	if (!q->cmd_args[1])
		return (export_all(s->env));
	i = 1;
	while (q->cmd_args[i])
	{
		new = finder(s->env, q->cmd_args[i]);
		if (keyerror(q->cmd_args[i]))
			return ((printf(\
			"minishell: export: `%s\': not a valid identifier\n", \
			q->cmd_args[i]) * 0) + 1);
		else if (new)
		{
			free(((t_cont *)new->content)->value);
			if (ft_strchr(q->cmd_args[i], '='))
				((t_cont *)new->content)->value = \
				ft_strdup(ft_strchr(q->cmd_args[i], '=') + 1);
			else
				((t_cont *)new->content)->value = ft_strdup("");
		}
		else
			ft_lstadd_back(&s->env, ft_lstnew(envar(q->cmd_args[i])));
		i++;
	}
	return (0);
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
// 	printf("created \n\n\n");
// 	t_seq q;
// 	q.cmd_args = ft_split("export lal pfad=wegge pfad=weg pfadler=heyo", ' ');
// 	ms_export(&s, &q);
// 	printf("added 2 \n\n\n");
// 	q.cmd_args = ft_split("unset pfad=weg pfad", ' ');
// 	ms_unset(&s, &q);
// 	ms_env(&s);
// 	return (0);
// }
