/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:49:53 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/02 18:27:47 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


/* Créer un node */
t_node	*create_node(int nb)
{
	t_node	*node;
	node = (t_node *) malloc(sizeof(t_node));
		if (!node)
			return (NULL);
	node->value = nb;
	node->index = -1;
	node->next = NULL;

	return(node);
}

// renvoie le denier node de la liste
t_node	*node_last(t_node *head)
{
	if (!head)
		return (NULL);
	t_node	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

// met le node en haut de la liste
void	add_node_top(t_node **stack, t_node *node)
{
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

// node en fin de liste
void	add_node_bot(t_node **stack, t_node *node)
{
	t_node *temp;

	if(!node)
		return ;
	if (*stack)
	{
		temp = node_last(*stack);
		temp->next = node;
	}
	else
		*stack = node;
}

void	create_stack(char	**argv, int argc, t_node **stack)
{
	int			i;
	t_node		*new_node;

	i = 0;
	if (argc != 2)
		i = 1;
	while (argv[i])
	{
		new_node = create_node(ft_atoi(argv[i]));
		add_node_bot(stack, new_node);
		i++;
	}
	if (argc == 2)
		free_all(argv);
}
