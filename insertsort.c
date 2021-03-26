/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:52:34 by user42            #+#    #+#             */
/*   Updated: 2021/03/26 16:45:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void
	rotate_opti(t_stack *a, t_stack *b, int idx)
{
	if (idx >= a->top / 2)
	{
		idx = (a->top - 1) - idx;
		while (idx-- > 0)
		{
			stack_operation(a, b, RA);
			ft_putendl_fd("ra", STDOUT);
		}
	}
	else
	{
		idx++;
		while (idx-- > 0)
		{
			stack_operation(a, b, RRA);
			ft_putendl_fd("rra", STDOUT);
		}
	}
}

static int
	getinsertidx(t_stack *a, int nb_to_insert)
{
	int	i;

	if (a->top == 2)
		return (a->top - 1);
	i = 1;
	while (i < a->top)
	{
		if (a->items[i] < nb_to_insert
		&& nb_to_insert < a->items[i - 1])
			return (i);
		i++;
	}
	return (-1);
}

void
	insertsort(t_stack *a, t_stack *b)
{
	while (!issorted(a, ascending, getibval(a)))
	{
		if (a->items[a->top -1] > a->items[a->top - 2]
		&& a->items[a->top -1] > a->items[0])
		{
			stack_operation(a, b, SA);
			ft_putendl_fd("sa", STDOUT);
		}
		else if (a->items[a->top - 1] < a->items[a->top - 2]
		&& a->items[a->top - 2] < a->items[0])
		{
			stack_operation(a, b, RA);
			ft_putendl_fd("ra", STDOUT);
		}
		else
		{
			stack_operation(a, b, PB);
			ft_putendl_fd("pb", STDOUT);
		}
	}
	while (!issorted(a, ascending, 0) || b->top > 0)
	{
		if (b->top == 0)
		{
			rotate_opti(a, b, getilval(a));
			continue ;
		}
		else if (b->items[b->top - 1] > getbval(a))
		{
			rotate_opti(a, b, getilval(a));
			stack_operation(a, b, PA);
			ft_putendl_fd("pa", STDOUT);
		}
		else if (b->items[b->top - 1] < getlval(a))
		{
			rotate_opti(a, b, getilval(a));
			stack_operation(a, b, PA);
			ft_putendl_fd("pa", STDOUT);
		}
		else if (a->items[a->top - 1] < b->items[b->top - 1]
		&& b->items[b->top - 1] < a->items[a->top - 2])
		{
			stack_operation(a, b, PA);
			ft_putendl_fd("pa", STDOUT);
			stack_operation(a, b, SA);
			ft_putendl_fd("sa", STDOUT);
		}
		else if (a->items[a->top - 1] > b->items[b->top - 1]
		&& b->items[b->top - 1] > a->items[0])
		{
			stack_operation(a, b, PA);
			ft_putendl_fd("pa", STDOUT);
		}
		else
			rotate_opti(a, b, getinsertidx(a, b->items[b->top - 1]));
	}
}
