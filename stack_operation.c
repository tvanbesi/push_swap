/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:40:57 by user42            #+#    #+#             */
/*   Updated: 2021/03/24 14:17:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void
	stack_operation(t_stack *a, t_stack *b, int operation)
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
	else if (operation == RB)
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
}
