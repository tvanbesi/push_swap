/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_insertsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:24:31 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 10:31:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int
	getmove(int idx, int size)
{
	if (idx < size / 2)
		return (-(idx + 1));
	return (size - (idx + 1));
}

int
	getdist(int idx, int size)
{
	if (idx < size / 2)
		return (idx + 1);
	return (size - (idx + 1));
}

int
	getival(t_stack *stack, int val)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->items[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

int
	getbval_t(t_stack *stack, int threshold)
{
	int	r;
	int	i;

	r = getlval(stack);
	i = 0;
	while (i < stack->top)
	{
		if (stack->items[i] > r && stack->items[i] < threshold)
			r = stack->items[i];
		i++;
	}
	return (r);
}

int
	getlval_t(t_stack *stack, int threshold)
{
	int	r;
	int	i;

	r = getbval(stack);
	i = 0;
	while (i < stack->top)
	{
		if (stack->items[i] < r && stack->items[i] > threshold)
			r = stack->items[i];
		i++;
	}
	return (r);
}
