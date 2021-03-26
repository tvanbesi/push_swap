/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:08:55 by user42            #+#    #+#             */
/*   Updated: 2021/03/25 10:57:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <unistd.h>

static int
	getpivot(t_stack *stack)
{
	int	lowest;
	int	i;
	int	r;
	
	i = 0;
	lowest = stack->items[0];
	r = 0;
	while (i < stack->top)
	{
		if (stack->items[i] < lowest)
		{
			r = i;
			lowest = stack->items[i];
		}
		i++;
	}
	return (r);
}

void
	pivot(t_stack *a, t_stack *b)
{
	int	pivot;

	pivot = getpivot(a);
	if (pivot != a->top - 1)
	{
		if (pivot < a->top / 2)
		{
			pivot++;
			while (pivot-- > 0)
			{
				rrotate(a);
				ft_putendl_fd("rra", STDOUT);
			}
		}
		else
		{
			pivot = (a->top - 1) - pivot;
			while (pivot-- > 0)
			{
				rotate(a);
				ft_putendl_fd("ra", STDOUT);
			}
		}
	}
	ft_putendl_fd("pb", STDOUT);
	push(b, a);
}
