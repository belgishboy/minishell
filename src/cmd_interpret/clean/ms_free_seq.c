
#include "../../../inc/minishell.h"

void	free_seq(t_seq *seq)// close the fd?
{
	if (seq->seq)
		free(seq->seq);
	if (seq->split[0])
		free_2dstr(seq->split);
	if (seq->path_cmd)
		free(seq->path_cmd);
	if (seq->cmd_args[0])
		free_2dstr(seq->cmd_args);
}

void	clean_seq(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->seq[i])
	{
		printf("free 2d seq[%d]\n", i);
		free_seq(sh->seq[i]);
		printf("2d done\n free seq[%d]\n", i);
		free(sh->seq[i]);
		printf("free seq[%d] done\n", i);
		i ++;
	}
	free(sh->seq);
}
