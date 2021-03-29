/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:55:31 by user42            #+#    #+#             */
/*   Updated: 2021/03/29 15:29:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int
	getinsertidx_r(t_stack *a, int nb_to_insert)
{
	int	i;

	if (nb_to_insert > getbval(a) || nb_to_insert < getlval(a))
		return (getibval(a));
	i = 1;
	while (i < a->top)
	{
		if (a->items[i] > nb_to_insert
		&& nb_to_insert > a->items[i - 1])
			return (i - 1);
		i++;
	}
	return (i);
}

int
	getinsertidx(t_stack *a, int nb_to_insert)
{
	int	i;

	if (nb_to_insert > getbval(a) || nb_to_insert < getlval(a))
		return (getilval(a));
	i = 1;
	while (i < a->top)
	{
		if (a->items[i] < nb_to_insert
		&& nb_to_insert < a->items[i - 1])
			return (i - 1);
		i++;
	}
	return (i);
}

void
	put_on_top(t_stack *stack, int idx, int stack_id)
{
	if (idx >= stack->top / 2)
	{
		idx = (stack->top - 1) - idx;
		while (idx-- > 0)
		{
			rotate(stack);
			if (stack_id == A)
				ft_putendl_fd("ra", STDOUT);
			else if (stack_id == B)
				ft_putendl_fd("rb", STDOUT);
		}
	}
	else
	{
		idx++;
		while (idx-- > 0)
		{
			rrotate(stack);
			if (stack_id == A)
				ft_putendl_fd("rra", STDOUT);
			else
				ft_putendl_fd("rrb", STDOUT);
		}
	}
}

