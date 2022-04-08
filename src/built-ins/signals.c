#include "../../inc/minishell.h"

void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signum == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
		rl_on_new_line();
	}
	else if (signum == SIGQUIT)
	{
		return ;
	}
}

void	init_sig(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sighandler;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
}
