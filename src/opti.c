/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:34:57 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/13 20:42:58 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_node	**stack_a)
{
	if(stack_is_not_sorted(stack_a))
	{
		while(node_last(*stack_a)->index != 2)
			ra(stack_a);
		if(stack_is_not_sorted(stack_a))
			sa(stack_a);
	}
}

/*static void	print_stack(t_node	**stack)
{
	t_node	*head;

	head = *stack;
	while(head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}*/

void	sort_four(t_node	**stack_a)
{
	if(stack_is_not_sorted(stack_a))
	{
		while(node_last(*stack_a)->index != 3)
			ra(stack_a);
	 	if((*stack_a)->index > (*stack_a)->next->index)
				sa(stack_a);
		if(stack_is_not_sorted(stack_a))
			ra(stack_a);
		if((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		if(stack_is_not_sorted(stack_a))
			rra(stack_a);
		if((*stack_a)->index > (*stack_a)->next->index)
				sa(stack_a);
	}
}
