/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:35:36 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/11/02 19:18:52 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* vérifie que les args ne se répètent pas*/
static	int	check_repeat(int nb, char **argv, int i)
{
	i++;
	while(argv[i])
	{
		if(ft_atoi(argv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/* passe isdigit dans la chaîne */
static	int check_num(char *str)
{
	int	i;

	i = 0;
	if(str[0] == '-')
		i++;
	while(str[i])
	{
			if(!ft_isdigit(str[i]))
				return(0);
			i++;
	}
	return (1);
}

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

/* gros du parsing, split quand 2 args, et atoi quand plus*/

void	checking_entry(int argc, char **argv)
{
	int		i;
	long	tmpo;

	i = 0;
	tmpo = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			return ;
	}
	else
		i = 1;
	while (argv[i])
	{
		tmpo = ft_atoi(argv[i]);
		if(!*argv[i] || !check_num(argv[i]) || check_repeat(tmpo, argv, i))
			error("Error");
		tmpo = ft_atol(argv[i]);
		if(tmpo < -2147483648 || tmpo > 2147483647)
			error("Error");
		i++;
	}
	if (argc == 2)
		free_all(argv);
}

