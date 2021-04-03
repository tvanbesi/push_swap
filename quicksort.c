/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:08:55 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 17:06:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int
	getmedian(t_stack *a)
{
	int	r;
	int	i;
	int	chunk_size;

	r = getlval(a);
	i = 0;
	chunk_size = ft_min(a->top / 2 - 1, 50);
	while (i++ < chunk_size)
		r = getlval_t(a, r);
	return (r);
}

static void
	pivot(t_stack *a, t_stack *b)
{
	int	median;

	while (a->top > 5)
	{
		median = getmedian(a);
		while (getlval(a) <= median)
		{
			if (a->top == 5)
				break ;
			if (a->items[a->top - 1] <= median)
			{
				stack_operation(a, b, PB, 1);
				continue ;
			}
			stack_operation(a, b, RA, 1);
		}
	}
}

void
	quicksort(t_stack *a, t_stack *b)
{
	int	idx_to_insert_a;
	int	idx_to_insert_b;

	pivot(a, b);
	sort_fourfive(a, b);
	while (b->top)
	{
		if (getdist(getilval(b), b->top) < getdist(getibval(b), b->top))
			idx_to_insert_b = getilval(b);
		else
			idx_to_insert_b = getibval(b);
		idx_to_insert_a = getinsertidx(a, b->items[idx_to_insert_b]);
		rotate_opti(a, b, idx_to_insert_a, idx_to_insert_b);
		stack_operation(a, b, PA, 1);
	}
}
