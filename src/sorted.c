/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:07:57 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/15 14:42:45 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_is_sorted(t_node **stack)
{
	t_node	*current;

	current = *stack;
	if (!stack)
		exit(1);
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static	t_node	*get_min(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;
	int		min;

	min = INT_MAX;
	tmp = NULL;
	head = *stack;
	while (head)
	{
		if (head->index == -1)
		{
			if (head->value < min)
			{
				min = head->value;
				tmp = head;
			}
		}
		head = head->next;
	}
	return (tmp);
}

int	got_index(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == -1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	put_index(t_node	**stack)
{
	t_node	*head;
	int		index;

	index = 0;
	while (got_index(stack))
	{
		head = get_min(stack);
		if (!head)
			return ;
		head->index = index;
		index++;
	}
}

void	little_sorting(t_node	**stack_a, t_node	**stack_b)
{
	int	stack_taille;

	if (stack_is_sorted(stack_a) || stack_size(*stack_a) == 0
		|| stack_size(*stack_a) == 1)
		return ;
	stack_taille = stack_size(*stack_a);
	if (stack_taille == 2)
		sa(stack_a);
	else if (stack_taille == 3)
		sort_three(stack_a);
	else if (stack_taille == 4)
		sort_four(stack_a);
	else if (stack_taille == 5)
		sort_five(stack_a, stack_b);
}

