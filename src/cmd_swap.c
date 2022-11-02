/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:31:13 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/02 18:19:10 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node  **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_node	**stack_a, t_node	**stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
