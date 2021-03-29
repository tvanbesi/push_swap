/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:52:34 by user42            #+#    #+#             */
/*   Updated: 2021/03/29 16:07:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int
	getdist(int idx, int size)
{
	if (idx <= size / 2)
		return (idx + 1);
	return (size - (idx + 1));
}

static void
	rotate_chunk(t_stack *a, t_stack *b, int chunk_idx[2])
{
	int	d1;
	int	d2;

	(void)b;
	d1 = getdist(chunk_idx[0], a->top);
	d2 = getdist(chunk_idx[1], a->top);
	if (d1 < d2)
		put_on_top(a, chunk_idx[0], A);
	else
		put_on_top(a, chunk_idx[1], A);
}

static void
	getchunk(t_stack *a, int chunk[2], int chunk_idx[2])
{
	int	threshold;
	int	chunk_size;

	chunk_size = CHUNK_SIZE - 1;
	if (a->top < chunk_size + 1)
		chunk_size = a->top;
	chunk[0] = getlval(a);
	threshold = chunk[0];
	while (chunk_size-- > 0)
		threshold = getlval_t(a, threshold);
	chunk[1] = threshold;
	chunk_idx[0] = getival(a, chunk[0]);
	chunk_idx[1] = getival(a, chunk[1]);
}

static void
	update_chunk(t_stack *a, int chunk[2], int chunk_idx[2], int last_added)
{
	if (chunk[0] == last_added)
		chunk[0] = getlval(a);
	else if (chunk[1] == last_added)
		chunk[1] = getbval_t(a, chunk[1]);
	chunk_idx[0] = getival(a, chunk[0]);
	chunk_idx[1] = getival(a, chunk[1]);
}

static void
	all_to_a(t_stack *a, t_stack *b)
{
	put_on_top(b, getibval(b), B);
	while (b->top)
	{
		stack_operation(a, b, PA);
		ft_putendl_fd("pa", STDOUT);
	}
}

void
	insertsort(t_stack *a, t_stack *b)
{
	int	chunk[2];
	int	chunk_idx[2];

	while (a->top)
	{
		getchunk(a, chunk, chunk_idx);
		while (chunk[0] != chunk[1])
		{
			rotate_chunk(a, b, chunk_idx);
			if (b->top > 1)
				put_on_top(b, getinsertidx_r(b, a->items[a->top - 1]), B);
			stack_operation(a, b, PB);
			ft_putendl_fd("pb", STDOUT);
			update_chunk(a, chunk, chunk_idx, b->items[b->top - 1]);
		}
		put_on_top(a, getival(a, chunk[0]), A);
		put_on_top(b, getinsertidx_r(b, a->items[a->top - 1]), B);
		stack_operation(a, b, PB);
		ft_putendl_fd("pb", STDOUT);
		put_on_top(b, getibval(b), B);
	}
	all_to_a(a, b);
}
