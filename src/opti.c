/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:34:57 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/15 13:22:01 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/*static int	get_index_pos(int target, t_node **stack)
{
	t_node	*current;
	int		i;

	if (target >= stack_size(*stack))
		exit(1);
	current = *stack;
	i = 0;
	while (current->index != target)
	{
		current = current->next;
		i++;
	}
	return (i);
}

static int	index_is_in_pos(int index, int pos, t_node **stack)
{
	return (get_index_pos(index, stack) == pos);
}*/

/*void	sort_five(t_node **stack_a)
{
	int	currentnb;

	currentnb = 4;
	if (!stack_is_sorted(stack_a))
	{
		while (!index_is_in_pos(4, 0, stack_a)) // objectif 4????
		{
			if (get_index_pos(4, stack_a) <= 3)
				ra(stack_a);
			else
				rra(stack_a);
		}
		while (!index_is_in_pos(3, 0, stack_a)) // objectif 34???
		{
			if ((*stack_a)->index > (*stack_a)->next->index
				&& (*stack_a)->index >= currentnb)
				sa(stack_a);
			if (get_index_pos(3, stack_a) <= 3)
				ra(stack_a);
			else
				rra(stack_a);
		}
	}
}*/

/*
ra  = premier devient dernier
rra = dernier devient premier

4 {
	4???? 				{0}
	?4??? ra 4???? 		{1}
	??4?? ra ra 4???? 	{2}
	???4? rra rra 4???? {2}
	????4 rra 4???? 	{1}
} 4???? {min 0 max 2}

3 {
	43??? sa 34???						{1}
	4?3?? sa ?43?? ra 43??? sa 34???	{3}
	4??3? rra ?4??3 sa 4???3 rra 34???	{3}
	4???3 rra 34???						{1}
} 34??? {min 1 max 3}

2 {
	342?? ra 42??3 sa 24??3 rra 324?? sa 234?? {4}
	34?2? rra ?34?2 rra 2?43? sa ?234? ra 234? {4}
	34??2 rra 234??	{1}
} 234?? {min 1 max 4}

0 1 {
	23410 rra 02341 rra 10234 sa 01234	{3}
	23401 rra 12340 rra 01234			{2}
} 01234 {min 2 max 3}

Maxsum = 2 + 3 + 4 + 3 = 12

Moment pour sa : [prev, current] = 3  43??? 4?3?? ?4??3  = [0, 1] [0, 2] [1, 4]
								   2  42??3 324?? 2?43?  = [4, 1] [1, 0] [3, 0]
								   1  10234

doit swap si :
43??? sa 34??? | 0 > 1 si 0 et 1 sont >= 3(current_nb)
324?? sa 234?? | 0 > 1 si 0 et 1 sont >= 2(current_nb)
42??3 sa 24??3 | 0 > 1 si 0 et 1 sont >= 2(current_nb)
10234 sa 01234 | 0 > 1 si 0 et 1 sont >= 0(current_nb)

?4??3 sa 4???3 | coller 1 a 4 si 4=3(current) et 1=4(current+1)

4?3?? sa ?43?? | coller 0 a 2
2?43? sa ?234? | coller 0 a 2
*/

void	bony_sort_five(t_node	**stack_a, t_node	**stack_b)
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
		while((*stack_b)->index != 2)
			rb(stack_b);
		pa(stack_b, stack_a);
		if((*stack_b)->index < (*stack_b)->next->index)
			sb(stack_b);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
	}
}
