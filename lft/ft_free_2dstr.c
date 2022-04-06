/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2dstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:35:52 by vheymans          #+#    #+#             */
/*   Updated: 2022/04/06 16:20:07 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * frees each of *s and then s
 * @param s [char **]
 * @return void
*/
void	free_2dstr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i ++;
	}
	free(s);
}
