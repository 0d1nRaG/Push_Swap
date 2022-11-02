/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:24:07 by tcaborde          #+#    #+#             */
/*   Updated: 2021/11/05 16:03:20 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	j;

	i = 0;
	j = (unsigned char) c;
	s2 = (unsigned char *)s;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (s2[i] == j)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
