/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:19:14 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/31 03:22:34 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdio.h>
#include <signal.h>

void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signum == SIGINT)
	{
		printf("\n");
		printf("called sigint handler\n");
		//call the prompt function
	}
	else if (signum == SIGQUIT)
	{
		//call our exit-function
		printf("called the sigquit handler\n");
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
