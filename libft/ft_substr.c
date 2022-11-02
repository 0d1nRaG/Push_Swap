/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:37:26 by tcaborde          #+#    #+#             */
/*   Updated: 2022/09/30 19:35:57 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*buffer;

	i = 0;
	j = 0;
	buffer = malloc(sizeof(char) * len + 1);
	if (!buffer)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			buffer[j] = s[i];
			j++;
		}
		i++;
	}	
	buffer[j] = '\0';
	return (buffer);
}
