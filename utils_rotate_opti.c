/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate_opti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:15:57 by user42            #+#    #+#             */
/*   Updated: 2021/04/04 13:22:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void
	smart_rrotate(t_stack *a, t_stack *b, int d1, int d2)
{
	while (d1-- > 0)
	{
		stack_operation(a, b, RRR, 1);
		d2--;
		if (d2 == 0)
			break ;
	}
	while (d1-- > 0)
		stack_operation(a, b, RRA, 1);
	while (d2-- > 0)
		stack_operation(a, b, RRB, 1);
}

static void
	smart_rotate(t_stack *a, t_stack *b, int d1, int d2)
{
	while (d1-- > 0)
	{
		stack_operation(a, b, RR, 1);
		d2--;
		if (d2 == 0)
			break ;
	}
	while (d1-- > 0)
		stack_operation(a, b, RA, 1);
	while (d2-- > 0)
		stack_operation(a, b, RB, 1);
}

int
	d1_bigger_halfstack_b(t_stack *a, t_stack *b, int idx_a, int idx_b)
{
	int	m1;
	int	m2;
	int	d1;
	int	d2;

	m1 = getmove(idx_a, a->top);
	m2 = getmove(idx_b, b->top);
	d1 = getdist(idx_a, a->top);
	d2 = getdist(idx_b, b->top);
	if (d1 > b->top / 2)
	{
		if (m1 < 0)
			smart_rrotate(a, b, d1, b->top - d2);
		else if (m1 > 0)
			smart_rotate(a, b, d1, b->top - d2);
		return (1);
	}
	return (0);
}

int
	d2_bigger_halfstack_a(t_stack *a, t_stack *b, int idx_a, int idx_b)
{
	int	m1;
	int	m2;
	int	d1;
	int	d2;

	m1 = getmove(idx_a, a->top);
	m2 = getmove(idx_b, b->top);
	d1 = getdist(idx_a, a->top);
	d2 = getdist(idx_b, b->top);
	if (d2 > a->top / 2)
	{
		if (m2 < 0)
			smart_rrotate(a, b, a->top - d1, d2);
		else if (m2 > 0)
			smart_rotate(a, b, a->top - d1, d2);
		return (1);
	}
	return (0);
}
