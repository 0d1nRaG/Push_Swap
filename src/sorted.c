/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:07:57 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/03 11:08:39 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_is_sorted(t_node	**stack)
{
	t_node	*head;

	head = *stack;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (1);

		head = head->next;
	}
	return (0);
}

static	t_node	*get_min(t_node **stack)
{
	t_node	*head;
	t_node	*min;

	min = create_node(0);
	head = *stack;
	while (head)
	{
		if ((head->index = -1) && (head->value < min->value))
			min = head;
		head = head->next;
	}
	return (min);
}

int	got_index(t_node **stack)
{
	t_node *tmp;
	
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
		head->index = index;
		index++;
	}
}

/* void	little_sorting(t_node	**stack)
{
	int	stack_taille;

	if (stack_is_sorted(stack_a) || stack_size(*stack_a) == 0
		|| stack_size(*stack_a) == 1)
		return ;
	stack_taille = stack_size(*stack_a);
	if (stack_taille = 2)
		sa(stack_a);
	else if (stack_taille == 3)
		// tri ici pour 3 values
	else if (stack_taille == 4)
		// tri ici pour 4 values
	else if (stack_taille == 5)
		// tri ici pour 5 values
} */

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
