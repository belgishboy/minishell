/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:06:05 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/08 18:22:40 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	close_fd(void)
{
	int	i;

	i = 3;
	while (i < 1024)
	{
		close(i);
		i ++;
	}
	return (0);
}