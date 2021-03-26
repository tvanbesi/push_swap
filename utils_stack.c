/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:15:14 by user42            #+#    #+#             */
/*   Updated: 2021/03/26 16:45:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int
	issorted(t_stack *stack, int (*f)(int, int), int start_pos)
{
	int	i;

	i = 1;
	while (i < stack->top)
	{
		if (!f(stack->items[(i + start_pos - 1) % stack->top],
		stack->items[(i + start_pos) % stack->top]))
			return (0);
		i++;
	}
	return (1);
}

int
	getlval(t_stack *stack)
{
	int	r;
	int	i;

	r = stack->items[0];
	i = 0;
	while (i < stack->top)
	{
		if (stack->items[i] < r)
			r = stack->items[i];
		i++;
	}
	return (r);
}

int
	getbval(t_stack *stack)
{
	int	r;
	int	i;

	r = stack->items[0];
	i = 0;
	while (i < stack->top)
	{
		if (stack->items[i] > r)
			r = stack->items[i];
		i++;
	}
	return (r);
}

int
	getilval(t_stack *stack)
{
	int	lowest;
	int	r;
	int	i;

	lowest = stack->items[0];
	r = 0;
	i = 0;
	while (i < stack->top)
	{
		if (stack->items[i] < lowest)
		{
			lowest = stack->items[i];
			r = i;
		}
		i++;
	}
	return (r);
}

int
	getibval(t_stack *stack)
{
	int	biggest;
	int	r;
	int	i;

	biggest = stack->items[0];
	r = 0;
	i = 0;
	while (i < stack->top)
	{
		if (stack->items[i] > biggest)
		{
			biggest = stack->items[i];
			r = i;
		}
		i++;
	}
	return (r);
}
