/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:19:55 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 12:18:59 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// write a given char to a given file-directory
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
//int main()
//{
//	ft_putchar_fd('a', 1);
//}
