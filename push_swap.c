/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:58:03 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 15:11:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void
	push_swap(t_stack *a, t_stack *b)
{
	if (a->maxsize == 3)
		sort_three(a, b);
	else if (a->maxsize < 6)
		sort_fourfive(a, b);
	else
		quicksort(a, b);
	put_on_top(a, getilval(a), A);
}

static int
	atoi_argv(int argc, char **argv, int *items)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (invalidarg(argv[i]))
			return (-1);
		items[argc - 1 - i] = ft_atoi(argv[i]);
		i++;
	}
	return (0);
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
	if (atoi_argv(argc, argv, items_a) == -1)
		return (freeret(items_a, items_b, -1));
	setstack(&stack_a, argc - 1, argc - 1, items_a);
	setstack(&stack_b, argc - 1, 0, items_b);
	if (duplicates(&stack_a))
		return (freeret(items_a, items_b, 0));
	push_swap(&stack_a, &stack_b);
	free(items_a);
	free(items_b);
	return (0);
}
