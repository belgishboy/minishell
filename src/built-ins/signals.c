#include "../../inc/minishell.h"
#include <stdio.h>
#include <signal.h>

void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signum == SIGINT)
	{
		printf("\b\b\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		printf("\b\b");
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
