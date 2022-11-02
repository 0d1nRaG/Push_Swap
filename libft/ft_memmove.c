/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:42:06 by tcaborde          #+#    #+#             */
/*   Updated: 2021/11/08 17:01:42 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*tdst;
	const unsigned char	*tsrc;

	tdst = dst;
	tsrc = src;
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{		
			i--;
			tdst[i] = tsrc[i];
		}
	}
	if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
