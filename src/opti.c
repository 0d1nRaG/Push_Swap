/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:34:57 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/15 14:43:06 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_node	**stack)
{
	t_node	*head;
	t_node	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	sort_three(t_node **stack_a)
{
	if (!stack_is_sorted(stack_a))
	{
		while (node_last(*stack_a)->index != 2)
			ra(stack_a);
		if (!stack_is_sorted(stack_a))
			sa(stack_a);
	}
}

void	sort_four(t_node **stack_a)
{
	if (!stack_is_sorted(stack_a))
	{
		while (node_last(*stack_a)->index != 3)
			ra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		if (!stack_is_sorted(stack_a))
			ra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		if (!stack_is_sorted(stack_a))
			rra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
}

void	sort_five(t_node	**stack_a, t_node	**stack_b)
{
	if (!stack_is_sorted(stack_a))
	{
		while (stack_size(*stack_a) > 2)
		{
			if ((*stack_a)->index < 3)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		while ((*stack_b)->index != 2)
			rb(stack_b);
		pa(stack_b, stack_a);
		if ((*stack_b)->index < (*stack_b)->next->index)
			sb(stack_b);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
	}
}
