#include "../../inc/minishell.h"

void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signum == SIGINT)
		sigint_handler(signum);
}

/**
 * @brief outsource the sinal action in order to prevent parent signals
 * @param signum [int] recieved signal
*/
void	sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		printf("\b\b");
		return ;
	}
}

void	init_sig(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sighandler;
	sigaction(SIGINT, &sig, NULL);
	// sigaction(SIGQUIT, &sig, NULL);
	signal(SIGQUIT, SIG_IGN);
}
