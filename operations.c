/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:52:59 by user42            #+#    #+#             */
/*   Updated: 2021/03/24 14:52:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int
	getoperation(char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		return (SA);
	else if (!ft_strncmp(line, "sb", 3))
		return (SB);
	else if (!ft_strncmp(line, "ss", 3))
		return (SS);
	else if (!ft_strncmp(line, "pa", 3))
		return (PA);
	else if (!ft_strncmp(line, "pb", 3))
		return (PB);
	else if (!ft_strncmp(line, "ra", 3))
		return (RA);
	else if (!ft_strncmp(line, "rb", 3))
		return (RB);
	else if (!ft_strncmp(line, "rr", 3))
		return (RR);
	else if (!ft_strncmp(line, "rra", 3))
		return (RRA);
	else if (!ft_strncmp(line, "rrb", 3))
		return (RRB);
	else if (!ft_strncmp(line, "rrr", 3))
		return (RRR);
	else
		return (INVALID);
}

void
	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top > 1)
	{
		tmp = stack->items[stack->top - 1];
		stack->items[stack->top - 1] = stack->items[stack->top - 2];
		stack->items[stack->top - 2] = tmp;
	}
}

void
	push(t_stack *dest, t_stack *src)
{
	if (src->top > 0)
	{
		dest->items[dest->top] = src->items[src->top - 1];
		dest->top++;
		src->top--;
	}
}

void
	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->top - 1;
	if (stack->top > 1)
	{
		tmp = stack->items[stack->top - 1];
		while (i > 0)
		{
			stack->items[i] = stack->items[i - 1];
			i--;
		}
		stack->items[0] = tmp;
	}
}

void
	rrotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->top > 1)
	{
		tmp = stack->items[0];
		while (i < stack->top - 1)
		{
			stack->items[i] = stack->items[i + 1];
			i++;
		}
		stack->items[stack->top - 1] = tmp;
	}
}
