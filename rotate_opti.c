/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_opti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:14:37 by user42            #+#    #+#             */
/*   Updated: 2021/04/04 13:41:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int
	only_one_stack_move(t_stack *a, t_stack *b, int idx_a, int idx_b)
{
	int	m1;
	int	m2;

	m1 = getmove(idx_a, a->top);
	m2 = getmove(idx_b, b->top);
	if (m1 == 0 || m2 == 0)
	{
		if (m1 == 0)
			put_on_top(b, idx_b, B);
		else
			put_on_top(a, idx_a, A);
		return (1);
	}
	return (0);
}

static int
	both_stack_rrotate(t_stack *a, t_stack *b, int idx_a, int idx_b)
{
	int	m1;
	int	m2;
	int	d1;
	int	d2;

	m1 = getmove(idx_a, a->top);
	m2 = getmove(idx_b, b->top);
	d1 = getdist(idx_a, a->top);
	d2 = getdist(idx_b, b->top);
	if (m1 < 0 && m2 < 0)
	{
		if (d1 < d2)
			smart_rrotate_b(a, b, d1, d2);
		else
			smart_rrotate_a(a, b, d2, d1);
		return (1);
	}
	return (0);
}

static int
	both_stack_rotate(t_stack *a, t_stack *b, int idx_a, int idx_b)
{
	int	m1;
	int	m2;
	int	d1;
	int	d2;

	m1 = getmove(idx_a, a->top);
	m2 = getmove(idx_b, b->top);
	d1 = getdist(idx_a, a->top);
	d2 = getdist(idx_b, b->top);
	if (m1 > 0 && m2 > 0)
	{
		if (d1 < d2)
			smart_rotate_b(a, b, d1, d2);
		else
			smart_rotate_a(a, b, d1, d2);
		return (1);
	}
	return (0);
}

void
	rotate_opti(t_stack *a, t_stack *b, int idx_a, int idx_b)
{
	int	m1;
	int	m2;
	int	d1;
	int	d2;

	m1 = getmove(idx_a, a->top);
	m2 = getmove(idx_b, b->top);
	d1 = getdist(idx_a, a->top);
	d2 = getdist(idx_b, b->top);
	if (only_one_stack_move(a, b, idx_a, idx_b))
		return ;
	else if (both_stack_rrotate(a, b, idx_a, idx_b))
		return ;
	else if (both_stack_rotate(a, b, idx_a, idx_b))
		return ;
	else if (d1_bigger_halfstack_b(a, b, idx_a, idx_b))
		return ;
	else if (d2_bigger_halfstack_a(a, b, idx_a, idx_b))
		return ;
	else
	{
		put_on_top(a, idx_a, A);
		put_on_top(b, idx_b, B);
	}
}
