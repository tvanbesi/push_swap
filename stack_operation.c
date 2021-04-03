/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:40:57 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 15:11:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void
	print_operation(int operation)
{
	if (operation == SA)
		ft_putendl_fd("sa", STDOUT);
	else if (operation == SB)
		ft_putendl_fd("sb", STDOUT);
	else if (operation == SS)
		ft_putendl_fd("ss", STDOUT);
	else if (operation == PA)
		ft_putendl_fd("pa", STDOUT);
	else if (operation == PB)
		ft_putendl_fd("pb", STDOUT);
	else if (operation == RA)
		ft_putendl_fd("ra", STDOUT);
	else if (operation == RB)
		ft_putendl_fd("rb", STDOUT);
	else if (operation == RR)
		ft_putendl_fd("rr", STDOUT);
	else if (operation == RRA)
		ft_putendl_fd("rra", STDOUT);
	else if (operation == RRB)
		ft_putendl_fd("rrb", STDOUT);
	else if (operation == RRR)
		ft_putendl_fd("rrr", STDOUT);
}

static void
	stack_operation2(t_stack *a, t_stack *b, int operation, int print)
{
	if (operation == RB)
		rotate(b);
	else if (operation == RR)
	{
		rotate(a);
		rotate(b);
	}
	else if (operation == RRA)
		rrotate(a);
	else if (operation == RRB)
		rrotate(b);
	else if (operation == RRR)
	{
		rrotate(a);
		rrotate(b);
	}
	if (print)
		print_operation(operation);
}

void
	stack_operation(t_stack *a, t_stack *b, int operation, int print)
{
	if (operation == SA)
		swap(a);
	else if (operation == SB)
		swap(b);
	else if (operation == SS)
	{
		swap(a);
		swap(b);
	}
	else if (operation == PA)
		push(a, b);
	else if (operation == PB)
		push(b, a);
	else if (operation == RA)
		rotate(a);
	stack_operation2(a, b, operation, print);
}
