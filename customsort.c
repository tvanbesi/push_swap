/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:11:21 by user42            #+#    #+#             */
/*   Updated: 2021/03/29 14:31:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void
	sort_three(t_stack *a, t_stack *b)
{
	if (!issorted(a, ascending, getibval(a)))
	{
		stack_operation(a, b, SA);
		ft_putendl_fd("sa", STDOUT);
	}
	put_on_top(a, getilval(a), A);
}

void
	sort_fourfive(t_stack *a, t_stack *b)
{
	if (issorted(a, ascending, getibval(a)))
		put_on_top(a, getilval(a), A);
	else
	{
		while (a->top > 3)
		{
			stack_operation(a, b, PB);
			ft_putendl_fd("pb", STDOUT);
		}
		if (!issorted(a, ascending, getibval(a)))
		{
			stack_operation(a, b, SA);
			ft_putendl_fd("sa", STDOUT);
		}
		while (!issorted(a, ascending, 0) || b->top > 0)
		{
			if (b->top == 0)
				put_on_top(a, getilval(a), A);
			else
			{
				put_on_top(a, getinsertidx(a, b->items[b->top - 1]), A);
				stack_operation(a, b, PA);
				ft_putendl_fd("pa", STDOUT);
			}
		}
	}
}
