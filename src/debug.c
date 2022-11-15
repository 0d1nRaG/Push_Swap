/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:58:43 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/15 13:14:14 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_node	**stack_a, t_node **stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	ft_putstr_fd("[Stack A] : ", 1);
	while (current_a)
	{
		ft_putnbr_fd(current_a->value, 1);
		ft_putstr_fd(" ", 1);
		current_a = current_a->next;
	}
	ft_putstr_fd("  [Stack B] : ", 1);
	while (current_b)
	{
		ft_putnbr_fd(current_b->value, 1);
		ft_putstr_fd(" ", 1);
		current_b = current_b->next;
	}
	ft_putstr_fd("\n", 1);
}

void	print_stack(t_node	**stack)
{
	t_node	*current;

	current = *stack;
	ft_putstr_fd("[Stack] : ", 1);
	while (current)
	{
		ft_putnbr_fd(current->value, 1);
		ft_putstr_fd(" ", 1);
		current = current->next;
	}
	ft_putstr_fd("\n", 1);
}
