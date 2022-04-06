
#include "../../../inc/minishell.h"

void	free_seq(t_seq *seq)// close the fd?
{
	if (seq->seq)
		free(seq->seq);
	if (seq->split)
		free_2dstr(seq->split);
	if (seq->path_cmd)
		free(seq->path_cmd);
	if (seq->cmd_args)
		free_2dstr(seq->cmd_args);
}

void	clean_seq(t_shell *sh)//free input?
{
	int	i;

	i = 0;
	while (sh->seq[i])
	{
		free_seq(sh->seq[i]);
		free(sh->seq[i]);
		i ++;
	}
	free(sh->seq);
}
