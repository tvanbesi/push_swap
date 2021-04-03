/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:52:34 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 15:14:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void
	all_to_a(t_stack *a, t_stack *b)
{
	put_on_top(b, getibval(b), B);
	while (b->top)
		stack_operation(a, b, PA, 1);
}

void
	insertsort(t_stack *a, t_stack *b)
{
	int	idx_to_insert_a;
	int	idx_to_insert_b;

	while (a->top)
	{
		if (getdist(getilval(a), a->top) < getdist(getibval(a), a->top))
			idx_to_insert_a = getilval(a);
		else
			idx_to_insert_a = getibval(a);
		if (b->top > 1)
		{
			idx_to_insert_b = getinsertidx_r(b, a->items[idx_to_insert_a]);
			if (idx_to_insert_b == b->top)
				put_on_top(a, idx_to_insert_a, A);
			else
				rotate_opti(a, b, idx_to_insert_a, idx_to_insert_b);
		}
		else
			put_on_top(a, idx_to_insert_a, A);
		stack_operation(a, b, PB, 1);
	}
	all_to_a(a, b);
}
