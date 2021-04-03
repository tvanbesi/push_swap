/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:11:21 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 17:05:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void
	sort_three(t_stack *a, t_stack *b)
{
	if (!issorted(a, ascending, getibval(a)))
		stack_operation(a, b, SA, 1);
}

static void
	insert_two(t_stack *a, t_stack *b, int to_insert_1, int to_insert_2)
{
	if (getdist(getinsertidx(a, to_insert_2), a->top)
	< getdist(getinsertidx(a, to_insert_1), a->top))
	{
		rotate_opti(a, b, getinsertidx(a, to_insert_2),
		getival(b, to_insert_2));
		stack_operation(a, b, PA, 1);
		rotate_opti(a, b, getinsertidx(a, to_insert_1),
		getival(b, to_insert_1));
		stack_operation(a, b, PA, 1);
	}
	else
	{
		rotate_opti(a, b, getinsertidx(a, to_insert_1),
		getival(b, to_insert_1));
		stack_operation(a, b, PA, 1);
		rotate_opti(a, b, getinsertidx(a, to_insert_2),
		getival(b, to_insert_2));
		stack_operation(a, b, PA, 1);
	}
}

static void
	order_stack(t_stack *a, t_stack *b, int to_insert)
{
	put_on_top(a, getinsertidx(a, to_insert), A);
	stack_operation(a, b, PA, 1);
}

void
	sort_fourfive(t_stack *a, t_stack *b)
{
	int	to_insert_1;
	int	to_insert_2;

	if (issorted(a, ascending, getibval(a)))
		put_on_top(a, getilval(a), A);
	else
	{
		while (a->top > 3)
			stack_operation(a, b, PB, 1);
		sort_three(a, b);
		to_insert_2 = -1;
		to_insert_1 = b->items[b->top - 1];
		if (b->top > 1)
			to_insert_2 = b->items[b->top - 2];
		while (!issorted(a, ascending, 0) || b->top > 0)
		{
			if (b->top == 0 || a->top == 5)
				break ;
			else if (b->top > 1)
				insert_two(a, b, to_insert_1, to_insert_2);
			else
				order_stack(a, b, to_insert_1);
		}
	}
}
