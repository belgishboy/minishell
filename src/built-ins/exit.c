#include "../../inc/minishell.h"

void	cleanup_env(t_list *l)
{
	t_list	*tmp;
	t_list	*t;

	tmp = l;
	while (tmp != NULL)
	{
		t = tmp->next;
		delvar(tmp);
		tmp = t;
	}
}

void	ms_exit(t_shell *s, t_seq *q)
{
	printf("exiting, but yet in a child process lol\n");
	if (q->cmd_args[1])
	{
		if (!ft_isnumeric(q->cmd_args[1]))
			err_num = 255;
		else if (q->cmd_args[2])
		{
			err_num = 1;
			return ;
		}
		else
			err_num = ft_atoi(q->cmd_args[1]);
	}
	if (s->seq)
		clean_seq(s);
	if (s->env)
		cleanup_env(s->env);
	if (s->input)
		free(s->input);
	exit(err_num);
}
