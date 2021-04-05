/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_smart_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:41:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/04 13:42:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void
	smart_rrotate_b(t_stack *a, t_stack *b, int d1, int d2)
{
	while (d1-- > 0)
	{
		stack_operation(a, b, RRR, 1);
		d2--;
	}
	while (d2-- > 0)
		stack_operation(a, b, RRB, 1);
}

void
	smart_rrotate_a(t_stack *a, t_stack *b, int d1, int d2)
{
	while (d1-- > 0)
	{
		stack_operation(a, b, RRR, 1);
		d2--;
	}
	while (d2-- > 0)
		stack_operation(a, b, RRA, 1);
}

void
	smart_rotate_b(t_stack *a, t_stack *b, int d1, int d2)
{
	while (d1-- > 0)
	{
		stack_operation(a, b, RR, 1);
		d2--;
	}
	while (d2-- > 0)
		stack_operation(a, b, RB, 1);
}

void
	smart_rotate_a(t_stack *a, t_stack *b, int d1, int d2)
{
	while (d1-- > 0)
	{
		stack_operation(a, b, RR, 1);
		d2--;
	}
	while (d2-- > 0)
		stack_operation(a, b, RA, 1);
}
