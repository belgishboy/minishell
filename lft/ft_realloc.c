/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:07:00 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/03/23 18:25:02 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t old_len, size_t add_len)
{
	char	*new;

	new = ft_calloc(old_len + add_len, 1);
	ft_memcpy(new, old, old_len);
	free(old);
	return ((void *)new);
}
