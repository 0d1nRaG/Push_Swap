/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:29:42 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/02 18:22:28 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	radix_sort(t_node	**stack_a, t_node	**stack_b)
{
	int	size;
	int	i;
	int	j;

	j = 0;
	size = stack_size(*stack_a);
	while (!stack_is_sorted(stack_a))
	{
		i = 0;
		while (i++ < size)
		{
			if ((((*stack_a)->index >> j) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_size(*stack_b) != 0)
			pa(stack_b, stack_a);
		j++;
	}
}
