/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:07:57 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/02 18:27:47 by tobiaslst        ###   ########.fr       */
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
			return (0);

		head = head->next;
	}
	return (1);
}

static	t_node	*get_min(t_node **stack)
{
	t_node	*head;
	t_node	*min;
	int		is_min;

	min = NULL;
	is_min = 0;
	head = *stack;

	if (head)
	{
		while (head)
		{
			if ((head->index = -1) && (!is_min || head->value < min->value))
			{
				min = head;
				is_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	put_index(t_node	**stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = get_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_min(stack);
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
