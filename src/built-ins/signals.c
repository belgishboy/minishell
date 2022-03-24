/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:19:14 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/24 14:23:16 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signum == SIGINT)
	{
		printf("\n");
		//call the prompt function
	}
	else if (signum == SIGQUIT)
		//call our exit-function
}

void	init_sig(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sighandler;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
}
