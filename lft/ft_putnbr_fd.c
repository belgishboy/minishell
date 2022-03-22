/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:27:59 by clems             #+#    #+#             */
/*   Updated: 2021/10/30 10:15:37 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// write an integer to a given file-directory
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + 48;
		write(fd, &c, 1);
	}
}
int main()
{
	int i = 1;
	while (i < 50)
	{
		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i++;
		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i++;
		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i++;
		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i++;
		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i -= 4;
		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
	}
	ft_putnbr_fd(50, 1);
}
