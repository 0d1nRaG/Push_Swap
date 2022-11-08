/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:29:42 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/08 14:25:34 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	radix_sort(t_node	**stack_a, t_node	**stack_b)
{
	int	size;
	int	i;
	int	j;

	j = 0;
	size = stack_size(*stack_a);
	put_index(stack_a);
	while (stack_is_sorted(stack_a))
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
