/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:29:33 by tcaborde          #+#    #+#             */
/*   Updated: 2021/11/03 17:54:10 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t				i;
	unsigned char		*stock;

	stock = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		stock[i] = (unsigned char)c;
		i++;
	}
	return (stock);
}
