/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:29:42 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/13 16:50:04 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	radix_sort(t_node	**stack_a, t_node	**stack_b)
{
	int	size;
	int	i;
	int	j;

	j = 0;
	size = stack_size(*stack_a);
	put_index(stack_a);
	while (!stack_is_not_sorted(stack_a))
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->index >> j) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		while (stack_size(*stack_b) != 0)
			pa(stack_b, stack_a);
		j++;
	}
}
