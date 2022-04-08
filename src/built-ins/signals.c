#include "../../inc/minishell.h"
#include <stdio.h>
#include <signal.h>

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
		printf("\b\b\n  %s", PROMPT);
		// rl_on_new_line();
		// rl_replace_line("", 0);
		// rl_redisplay();
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

// int	main(void)
// {
// 	printf("this is the start of the program\n");
// 	init_sig();
// 	printf("initialized sig handler\n");
// 	while (1)
// 	{
// 	}
// 	return (0);
// }
