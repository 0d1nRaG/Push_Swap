/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:53:57 by tobiaslst         #+#    #+#             */
/*   Updated: 2021/11/19 15:30:12 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len_word(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	word_getsize(char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	total;

	i = 0;
	j = 0;
	total = 0;
	while (s[i])
	{
			j = len_word(s + i, c);
			if (j > 0)
			{
				total++;
				i--;
			}
		i += j;
		i++;
	}
	return (total);
}
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	size = word_getsize((char *)s, c);
	tab = malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		size = len_word((char *)s + i, c);
		if (size > 0)
		{
			tab[j] = ft_substr(s, i, size);
			j++;
			i--;
		}
		i += size;
		i++;
	}
	tab[j] = 0;
	return (tab);
}
