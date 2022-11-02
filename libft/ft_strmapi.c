/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:13:59 by tcaborde          #+#    #+#             */
/*   Updated: 2021/11/19 15:30:45 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	s2 = malloc(ft_strlen(s) + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s, ft_strlen(s) + 1);
	while (s2[i])
	{
		s2[i] = (*f)(i, s2[i]);
		i++;
	}
	return (s2);
}
