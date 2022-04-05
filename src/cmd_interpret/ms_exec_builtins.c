#include "../../inc/minishell.h"

void	ms_exec_builtins(t_shell *s, t_seq *q)
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
		exit(42) // work in progress
}
