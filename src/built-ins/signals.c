#include "../../inc/minishell.h"

void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signum == SIGUSR1 || signum == SIGINT)
		sigint_handler(signum);
}

/**
 * @brief outsource the sinal action in order to prevent parent signals
 * @param signum [int] recieved signal
*/
void	sigint_handler(int signum)
{
	static int	check;

	check = 1;
	if (signum == SIGUSR1)
		check *= -1;
	if (signum == SIGINT && check < 0)
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
	sigaction(SIGUSR1, &sig, NULL);
}
