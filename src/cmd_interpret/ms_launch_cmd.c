/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_launch_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:59:28 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/05 15:26:50 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * 
*/
int	launch_cmd(t_shell *sh)
{
	int	tmp_in;
	int	tmp_out;

	tmp_in = dup(0);
	tmp_out = dup(1);
	return (0);
}