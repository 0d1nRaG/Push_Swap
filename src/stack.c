/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:17:06 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/13 20:43:02 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_node *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (stack_size(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	push(t_node **stack_took, t_node **stack_drop)
{
	t_node	*tmp;

	if (stack_size(*stack_took) == 0)
		return ;
	tmp = *stack_took;
	*stack_took = (*stack_took)->next;
	add_node_top(stack_drop, tmp);
}

void	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (stack_size(*stack) < 2)
		return ;
	tail = node_last(*stack);
	head = *stack;
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;
}

void	rev_rotate(t_node **stack)
{
	t_node	*prev_last;
	t_node	*last;

	if (stack_size(*stack) < 2)
		return ;
	prev_last = *stack;
	while (prev_last->next->next)
		prev_last = prev_last->next;
	last = prev_last->next;
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
