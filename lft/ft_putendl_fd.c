/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:16:07 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 12:19:39 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// write a given string to a given file-directory, putting a
// newline char at the end
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	write(fd, "\n", 1);
}
//int main()
//{
//	ft_putendl_fd("examlpleString", 1);
//}
