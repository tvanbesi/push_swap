/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:58:03 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 17:33:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void
	checker(t_stack *a, t_stack *b)
{
	int		r;
	int		operation;
	char	*line;

	while ((r = prompt(&line)) > 0)
	{
		operation = getoperation(line);
		free(line);
		if (operation == INVALID)
		{
			ft_putendl_fd("Error", STDERR);
			return ;
		}
		stack_operation(a, b, operation, 0);
	}
	if (r == 0)
	{
		free(line);
		if (issorted(a, ascending, 0) && b->top == 0)
			ft_putendl_fd("OK", STDOUT);
		else
			ft_putendl_fd("KO", STDOUT);
	}
	else if (r == -1)
		ft_putendl_fd("Error", STDERR);
}

int
	main(int argc, char **argv)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;
	int		*items_a;
	int		*items_b;

	i = 1;
	if (argc < 2)
		return (0);
	if (!(items_a = malloc((argc - 1) * sizeof(int)))
	|| !(items_b = malloc((argc - 1) * sizeof(int))))
		return (-1);
	while (i < argc)
	{
		if (invalidarg(argv[i]))
			return (freeret(items_a, items_b, -1));
		items_a[argc - 1 - i] = ft_atoi(argv[i]);
		i++;
	}
	//if (duplicates(&stack_a))
	//	return (freeret(items_a, items_b, 0));
	setstack(&stack_a, argc - 1, argc - 1, items_a);
	setstack(&stack_b, argc - 1, 0, items_b);
	checker(&stack_a, &stack_b);
	free(items_a);
	free(items_b);
	return (0);
}
