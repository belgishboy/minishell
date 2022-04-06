#include "../../../inc/minishell.h"

void	ms_exec_builtins(t_shell *s, t_seq *q)
{
	char	**p_env;

	p_env = env_copy(s->env);
	if (q->wht_cmd == 1)
		execve(q->path_cmd, q->cmd_args, p_env);
	else
	{
		if (q->wht_cmd == 2)
			ms_echo(q->cmd_args);
		else if (q->wht_cmd == 3)
			cd(q->cmd_args, s);
		else if (q->wht_cmd == 4)
			pwd();
		else if (q->wht_cmd == 5)
			ms_export(s, q);
		else if (q->wht_cmd == 6)
			ms_unset(s, q);
		else if (q->wht_cmd == 7)
			ms_env(s, q);
		else if (q->wht_cmd == 8)
			ms_exit(s, q);
		exit(0); //KILL CHILD
	}
	del_list(p_env);
}
