/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:30:13 by tobiaslst         #+#    #+#             */
/*   Updated: 2021/11/17 21:42:24 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  whats_my_len(int n)
{
	int	i;

	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	i = 1;
	if (n < 0)
	{    
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int n)
{
	int		len;
	int		i;
	char	*s;

	len = whats_my_len(n);
	i = len;
	s = malloc(sizeof(char) * len +  1);
	if (!s)
		return (NULL);
	if (n >= 0 && s)
	{
		len--;
		s[len] = '0' + (n % 10);
		n = n / 10;
		while (n != 0)
		{
			len--;
			s[len] = '0' + (n % 10);
			n = n / 10;
		}
	}
	else if (s)
	{
		len--;
		s[len] = '0' - (n % 10);
		n = n / 10;
		while (n != 0)
		{
			len--;
			s[len] = '0' - (n % 10);
			n = n / 10;
		}
		len--;
		s[len] = '-';
	}
	s[i] = '\0';
	return (s);
}