/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:58:03 by user42            #+#    #+#             */
/*   Updated: 2021/03/29 15:04:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int
	invalidarg(char *arg)
{
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
		if (!ft_isdigit(*arg++))
			return (1);
	return (0);
}

static void
	push_swap(t_stack *a, t_stack *b)
{
	if (a->maxsize == 2)
	{
		stack_operation(a, b, SA);
		ft_putendl_fd("sa", STDOUT);
	}
	else if (a->maxsize == 3)
		sort_three(a, b);
	else if (a->maxsize < 6)
		sort_fourfive(a, b);
	else if (a->maxsize <= 100)
		insertsort(a, b);
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
		{
			ft_putendl_fd("Error", STDERR);
			free(items_a);
			free(items_b);
			return (-1);
		}
		items_a[argc - 1 - i] = ft_atoi(argv[i]);
		i++;
	}
	// check for duplicates and over INTMAX
	stack_a.maxsize = argc - 1;
	stack_a.top = stack_a.maxsize;
	stack_a.items = items_a;
	stack_b.maxsize = stack_a.maxsize;
	stack_b.top = 0;
	stack_b.items = items_b;
	push_swap(&stack_a, &stack_b);
	free(items_a);
	free(items_b);
	return (0);
}
