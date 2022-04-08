#include "../../../inc/minishell.h"
/**
 * @brief execute the builtins and commands respectively in child and parent
 * @param s [t_shell*] shell
 * @param q [t_seq*]	sequence
 * @param pid [pid_t]	child-or-not pid
*/
void	ms_exec_builtins(t_shell *s, t_seq *q, pid_t pid)
{
	char	**p_env;

	p_env = env_copy(s->env);
	if (q->wht_cmd == 1 && !pid)
		err_num = execve(q->path_cmd, q->cmd_args, p_env);
	else
	{
		if (q->wht_cmd == 2)
			ms_echo(q->cmd_args, pid);
		else if (q->wht_cmd == 3)
			cd(q->cmd_args, s, pid);
		else if (q->wht_cmd == 4)
			pwd(pid);
		else if (q->wht_cmd == 5)
			ms_export(s, q, pid);
		else if (q->wht_cmd == 6)
			ms_unset(s, q, pid);
		else if (q->wht_cmd == 7)
			ms_env(s, q, pid);
		else if (q->wht_cmd == 8)
			ms_exit(s, q, pid);
		if (!pid)
			exit(0);
	}
	del_list(p_env);
}
