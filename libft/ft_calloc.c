/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:28:42 by tcaborde          #+#    #+#             */
/*   Updated: 2022/09/30 19:35:56 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (nmemb == 0)
		return (malloc(0));
	if (size == 0)
		return (malloc(0));
	tmp = malloc(nmemb * size);
	if (tmp == NULL)
		return (NULL);
	ft_memset((unsigned char *)tmp, 0, nmemb * size);
	return (tmp);
}
